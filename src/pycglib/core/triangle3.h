#pragma once
#include "core/types.h"

// --- Operations ---
bool    triangle3_eq(const Triangle3& a, const Triangle3& b);
bool    triangle3_neq(const Triangle3& a, const Triangle3& b);
Point3  triangle3_vertex(const Triangle3& t, int i);
Plane3  triangle3_supporting_plane(const Triangle3& t);

// --- Predicates ---
bool triangle3_is_degenerate(const Triangle3& t);
bool triangle3_has_on(const Triangle3& t, const Point3& p);

// --- Miscellaneous ---
double triangle3_squared_area(const Triangle3& t);
Bbox3  triangle3_bbox(const Triangle3& t);