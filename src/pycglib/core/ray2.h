#pragma once
#include "core/types.h"

// --- Operations ---
bool       ray2_eq(const Ray2& a, const Ray2& b);
bool       ray2_neq(const Ray2& a, const Ray2& b);
Point2     ray2_source(const Ray2& r);
Point2     ray2_point(const Ray2& r, double i);
Direction2 ray2_direction(const Ray2& r);
Vector2    ray2_to_vector(const Ray2& r);
Line2      ray2_supporting_line(const Ray2& r);
Ray2       ray2_opposite(const Ray2& r);

// --- Predicates ---
bool ray2_is_degenerate(const Ray2& r);
bool ray2_is_horizontal(const Ray2& r);
bool ray2_is_vertical(const Ray2& r);
bool ray2_has_on(const Ray2& r, const Point2& p);
bool ray2_collinear_has_on(const Ray2& r, const Point2& p);