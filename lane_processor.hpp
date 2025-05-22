#pragma once
#include "utilities.hpp"
#include <memory>
#include <mutex>
#include <iostream>

using namespace std;

class LaneProcessor{
public:
    void processData(shared_ptr<Lanedata> &lanedata,shared_ptr<ProcessedLaneInfo> &laneinfo, mutex &sensormtx, mutex &processormtx);
       
};