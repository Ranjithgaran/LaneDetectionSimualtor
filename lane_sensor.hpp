#pragma once
#include "utilities.hpp"
#include <thread>
#include <mutex>
#include <memory>
#include <random>
#include <iostream>

using namespace std;

class LaneSensor {
public:
    void generateData(shared_ptr<Lanedata> &lanedata, mutex &mtx);
};