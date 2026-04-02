#pragma once
#include "core/types.h"

// --- Transform operations ---
Point2     aff2_transform_point(const AffTransformation2& t, const Point2& p);
Vector2    aff2_transform_vector(const AffTransformation2& t, const Vector2& v);
Direction2 aff2_transform_direction(const AffTransformation2& t, const Direction2& d);
Line2      aff2_transform_line(const AffTransformation2& t, const Line2& l);

// --- Miscellaneous ---
AffTransformation2 aff2_mul(const AffTransformation2& a, const AffTransformation2& b);
AffTransformation2 aff2_inverse(const AffTransformation2& t);
bool               aff2_eq(const AffTransformation2& a, const AffTransformation2& b);
bool               aff2_is_even(const AffTransformation2& t);
bool               aff2_is_odd(const AffTransformation2& t);
bool               aff2_is_scaling(const AffTransformation2& t);
bool               aff2_is_translation(const AffTransformation2& t);
bool               aff2_is_rotation(const AffTransformation2& t);
bool               aff2_is_reflection(const AffTransformation2& t);

// --- Matrix entry access ---
double aff2_cartesian(const AffTransformation2& t, int i, int j);
double aff2_homogeneous(const AffTransformation2& t, int i, int j);