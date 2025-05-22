#pragma once 

struct Lanedata {
    float left_lane_position;
    float right_lane_position;
};

struct ProcessedLaneInfo{

    float lane_center_offset;
    bool is_dangerous;

};