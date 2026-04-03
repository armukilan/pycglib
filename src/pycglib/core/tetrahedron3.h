#pragma once
#include "core/types.h"

// --- Operations ---
bool   tetra3_eq(const Tetrahedron3& a, const Tetrahedron3& b);
bool   tetra3_neq(const Tetrahedron3& a, const Tetrahedron3& b);
Point3 tetra3_vertex(const Tetrahedron3& t, int i);

// --- Predicates ---
bool tetra3_is_degenerate(const Tetrahedron3& t);
int  tetra3_orientation(const Tetrahedron3& t);       // 1=CCW, -1=CW, 0=degenerate
int  tetra3_oriented_side(const Tetrahedron3& t, const Point3& p);   // 1, -1, 0
int  tetra3_bounded_side(const Tetrahedron3& t, const Point3& p);    // 1=inside, -1=outside, 0=boundary
bool tetra3_has_on_positive_side(const Tetrahedron3& t, const Point3& p);
bool tetra3_has_on_negative_side(const Tetrahedron3& t, const Point3& p);
bool tetra3_has_on_boundary(const Tetrahedron3& t, const Point3& p);
bool tetra3_has_on_bounded_side(const Tetrahedron3& t, const Point3& p);
bool tetra3_has_on_unbounded_side(const Tetrahedron3& t, const Point3& p);

// --- Miscellaneous ---
double tetra3_volume(const Tetrahedron3& t);
Bbox3  tetra3_bbox(const Tetrahedron3& t);