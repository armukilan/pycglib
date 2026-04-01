#pragma once
#include "core/types.h"

// --- Operations ---
bool      segment2_eq(const Segment2& a, const Segment2& b);
bool      segment2_neq(const Segment2& a, const Segment2& b);
Point2    segment2_source(const Segment2& s);
Point2    segment2_target(const Segment2& s);
Point2    segment2_min(const Segment2& s);
Point2    segment2_max(const Segment2& s);
Point2    segment2_vertex(const Segment2& s, int i);
Point2    segment2_point(const Segment2& s, int i);
double    segment2_squared_length(const Segment2& s);
Direction2 segment2_direction(const Segment2& s);
Vector2   segment2_to_vector(const Segment2& s);
Segment2  segment2_opposite(const Segment2& s);
Line2     segment2_supporting_line(const Segment2& s);

// --- Predicates ---
bool segment2_is_degenerate(const Segment2& s);
bool segment2_is_horizontal(const Segment2& s);
bool segment2_is_vertical(const Segment2& s);
bool segment2_has_on(const Segment2& s, const Point2& p);
bool segment2_collinear_has_on(const Segment2& s, const Point2& p);

// --- Miscellaneous ---
Bbox2 segment2_bbox(const Segment2& s);