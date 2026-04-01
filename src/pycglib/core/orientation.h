#pragma once
#include "core/types.h"

struct OrientationResult {
    int value;
    bool left_turn()  const { return value == 1; }
    bool right_turn() const { return value == -1; }
    bool collinear()  const { return value == 0; }
    std::string str() const {
        if (value == 1)  return "Left turn";
        if (value == -1) return "Right turn";
        return "Collinear";
    }
};

OrientationResult orientation_2(const Point2& p1, const Point2& p2, const Point2& p3);