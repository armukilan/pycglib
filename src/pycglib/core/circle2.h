#pragma once
#include "core/types.h"

// --- Access ---
bool   circle2_eq(const Circle2& a, const Circle2& b);
bool   circle2_neq(const Circle2& a, const Circle2& b);
Point2 circle2_center(const Circle2& c);
double circle2_squared_radius(const Circle2& c);
int    circle2_orientation(const Circle2& c);   // 1=CCW, -1=CW

// --- Predicates ---
bool circle2_is_degenerate(const Circle2& c);
int  circle2_oriented_side(const Circle2& c, const Point2& p);   // 1, -1, 0
int  circle2_bounded_side(const Circle2& c, const Point2& p);    // 1=inside, -1=outside, 0=boundary
bool circle2_has_on_positive_side(const Circle2& c, const Point2& p);
bool circle2_has_on_negative_side(const Circle2& c, const Point2& p);
bool circle2_has_on_boundary(const Circle2& c, const Point2& p);
bool circle2_has_on_bounded_side(const Circle2& c, const Point2& p);
bool circle2_has_on_unbounded_side(const Circle2& c, const Point2& p);

// --- Miscellaneous ---
Circle2 circle2_opposite(const Circle2& c);
Bbox2   circle2_bbox(const Circle2& c);