#include "lane_sensor.hpp"

void LaneSensor::generateData(shared_ptr<Lanedata> &lanedata, mutex &mtx){

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(1.8,3.8);

    while(true) {
        auto newdata = make_shared<Lanedata>();
        newdata->left_lane_position = dist(gen);
        newdata->right_lane_position = dist(gen);

        {
            lock_guard<mutex>lock(mtx);
            lanedata = newdata;
        }

        cout<<"[Sensor] generated L=" <<newdata->left_lane_position <<" R="<<newdata->right_lane_position<<endl;

        this_thread::sleep_for(chrono::seconds(1));
    }

}