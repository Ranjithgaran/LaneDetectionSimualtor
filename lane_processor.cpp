#include "lane_processor.hpp"
#include <thread>

void LaneProcessor::processData(shared_ptr<Lanedata> &lanedata, shared_ptr<ProcessedLaneInfo> &laneinfo, mutex &sensormtx, mutex &processormtx){
    while (true){
        shared_ptr<Lanedata> localdata;

        {
            lock_guard<mutex> lock(sensormtx);
            if(!lanedata) continue;
            localdata = lanedata;
        }

        float center = (localdata->left_lane_position+ localdata->right_lane_position)/2;
        float deviation = abs(3.0f - center);

        auto result = make_shared<ProcessedLaneInfo>();
        result->lane_center_offset = deviation;
        result->is_dangerous = deviation>0.5;

        {
            lock_guard<mutex> lock(processormtx);
            laneinfo = result;
        }

        cout<<"[Processor] Deviation:" <<deviation<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}