#pragma once
#include "core/types.h"

// --- Operations ---
bool   triangle2_eq(const Triangle2& a, const Triangle2& b);
bool   triangle2_neq(const Triangle2& a, const Triangle2& b);
Point2 triangle2_vertex(const Triangle2& t, int i);

// --- Predicates ---
bool triangle2_is_degenerate(const Triangle2& t);
int  triangle2_orientation(const Triangle2& t);      // 1=CCW, -1=CW, 0=degenerate
int  triangle2_oriented_side(const Triangle2& t, const Point2& p);   // 1, -1, 0
int  triangle2_bounded_side(const Triangle2& t, const Point2& p);    // 1=inside, -1=outside, 0=boundary
bool triangle2_has_on_positive_side(const Triangle2& t, const Point2& p);
bool triangle2_has_on_negative_side(const Triangle2& t, const Point2& p);
bool triangle2_has_on_boundary(const Triangle2& t, const Point2& p);
bool triangle2_has_on_bounded_side(const Triangle2& t, const Point2& p);
bool triangle2_has_on_unbounded_side(const Triangle2& t, const Point2& p);

// --- Miscellaneous ---
Triangle2 triangle2_opposite(const Triangle2& t);
double    triangle2_area(const Triangle2& t);
Bbox2     triangle2_bbox(const Triangle2& t);