#pragma once
#include "core/types.h"

// --- Access ---
bool   circle3_eq(const Circle3& a, const Circle3& b);
bool   circle3_neq(const Circle3& a, const Circle3& b);
Point3 circle3_center(const Circle3& c);
double circle3_squared_radius(const Circle3& c);
Plane3 circle3_supporting_plane(const Circle3& c);
Sphere3 circle3_diametral_sphere(const Circle3& c);
double circle3_area_divided_by_pi(const Circle3& c);
double circle3_approximate_area(const Circle3& c);
double circle3_squared_length_divided_by_pi_square(const Circle3& c);
double circle3_approximate_squared_length(const Circle3& c);

// --- Predicates ---
bool circle3_has_on(const Circle3& c, const Point3& p);

// --- Miscellaneous ---
Bbox3 circle3_bbox(const Circle3& c);