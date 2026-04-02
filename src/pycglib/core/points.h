#pragma once
#include "core/types.h"

// --- Arithmetic operators ---
Vector2 point2_sub(const Point2& a, const Point2& b);       // p - q → vector
Point2  point2_add_vector(const Point2& p, const Vector2& v); // p + v → point
Point2  point2_sub_vector(const Point2& p, const Vector2& v); // p - v → point
Point2  point2_iadd(Point2& p, const Vector2& v);            // p += v
Point2  point2_isub(Point2& p, const Vector2& v);            // p -= v

// --- Comparison operators ---
bool point2_eq(const Point2& a, const Point2& b);
bool point2_neq(const Point2& a, const Point2& b);
bool point2_lt(const Point2& a, const Point2& b);
bool point2_gt(const Point2& a, const Point2& b);
bool point2_le(const Point2& a, const Point2& b);
bool point2_ge(const Point2& a, const Point2& b);

// --- Vector2 operators ---
Vector2 vector2_add(const Vector2& a, const Vector2& b);
Vector2 vector2_sub(const Vector2& a, const Vector2& b);
Vector2 vector2_mul(const Vector2& a, double scalar);
Vector2 vector2_neg(const Vector2& v);

// --- Miscellaneous ---
Bbox2  point2_bbox(const Point2& p);
Point2 point2_from_weighted(const WeightedPoint2& wp);