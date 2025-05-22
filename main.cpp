#include "lane_sensor.hpp"
#include "lane_processor.hpp"
#include "lane_alert.hpp"
#include <thread>

using namespace std;

int main()
{
    shared_ptr<Lanedata> lanedata = nullptr;
    shared_ptr<ProcessedLaneInfo> laneinfo = nullptr;

    mutex sensormtx;
    mutex processormtx;
    mutex alertmtx;

    LaneSensor sensor;
    LaneProcessor processor;
    LaneAlert alert;

    thread sensorThread(&LaneSensor::generateData, &sensor, ref(lanedata), ref(sensormtx));
    thread processThread(&LaneProcessor::processData, &processor, ref(lanedata), ref(laneinfo), ref(sensormtx), ref(processormtx)); 
    thread alertThread(&LaneAlert::monitor, &alert, ref(laneinfo), ref(alertmtx));

    sensorThread.join();
    processThread.join();
    alertThread.join();

    return 0;
}