#pragma once
#include "utilities.hpp"
#include <memory>
#include <mutex>
#include <iostream>
using namespace std;

class LaneAlert{
public: 
    void monitor(shared_ptr<ProcessedLaneInfo> & laneinfo , mutex &mtx);
};