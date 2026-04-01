#pragma once
#include "core/types.h"

// --- Creation ---
Direction2 direction2_from_vector(const Vector2& v);
Direction2 direction2_from_segment(const Segment2& s);
Direction2 direction2_from_xy(double x, double y);

// --- Operations ---
bool       direction2_eq(const Direction2& a, const Direction2& b);
bool       direction2_neq(const Direction2& a, const Direction2& b);
bool       direction2_lt(const Direction2& a, const Direction2& b);
bool       direction2_gt(const Direction2& a, const Direction2& b);
bool       direction2_le(const Direction2& a, const Direction2& b);
bool       direction2_ge(const Direction2& a, const Direction2& b);
bool       direction2_counterclockwise_in_between(const Direction2& d, const Direction2& d1, const Direction2& d2);
Direction2 direction2_opposite(const Direction2& d);

// --- Miscellaneous ---
Vector2 direction2_vector(const Direction2& d);