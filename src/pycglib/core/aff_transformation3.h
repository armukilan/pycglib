#pragma once
#include "core/types.h"

// --- Transform operations ---
Point3     aff3_transform_point(const AffTransformation3& t, const Point3& p);
Vector3    aff3_transform_vector(const AffTransformation3& t, const Vector3& v);
Direction3 aff3_transform_direction(const AffTransformation3& t, const Direction3& d);
Plane3     aff3_transform_plane(const AffTransformation3& t, const Plane3& p);

// --- Miscellaneous ---
AffTransformation3 aff3_mul(const AffTransformation3& a, const AffTransformation3& b);
AffTransformation3 aff3_inverse(const AffTransformation3& t);
bool               aff3_eq(const AffTransformation3& a, const AffTransformation3& b);
bool               aff3_is_even(const AffTransformation3& t);
bool               aff3_is_odd(const AffTransformation3& t);
bool               aff3_is_scaling(const AffTransformation3& t);
bool               aff3_is_translation(const AffTransformation3& t);

// --- Matrix entry access ---
double aff3_cartesian(const AffTransformation3& t, int i, int j);
double aff3_homogeneous(const AffTransformation3& t, int i, int j);