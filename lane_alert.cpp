#include "lane_alert.hpp"
#include <thread>


void LaneAlert::monitor(shared_ptr<ProcessedLaneInfo> &laneinfo, mutex &mtx){
    while(true)
    {
        shared_ptr<ProcessedLaneInfo> localinfo;

        {
            lock_guard<mutex>lock(mtx);
            if(!laneinfo) continue;
            localinfo = laneinfo;
        }

        if(localinfo->is_dangerous) {
            cout<<"[Alert] Lane deviation too high! offset: " 
                << localinfo->lane_center_offset<<endl;
        }
        else {
            cout<<"[Alert] Lane deviation normal! offset: " 
                << localinfo->lane_center_offset<<endl;

        }

        this_thread::sleep_for(chrono::seconds(1));
    }
    
}