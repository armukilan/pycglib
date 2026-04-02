#include "core/points.h"

// --- Point2 arithmetic ---
Vector2 point2_sub(const Point2& a, const Point2& b) {
    auto result = a.p - b.p;
    return Vector2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Point2 point2_add_vector(const Point2& p, const Vector2& v) {
    auto result = p.p + v.v;
    return Point2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Point2 point2_sub_vector(const Point2& p, const Vector2& v) {
    auto result = p.p - v.v;
    return Point2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Point2 point2_iadd(Point2& p, const Vector2& v) {
    p.p = p.p + v.v;
    return p;
}

Point2 point2_isub(Point2& p, const Vector2& v) {
    p.p = p.p - v.v;
    return p;
}

// --- Point2 comparison ---
bool point2_eq(const Point2& a, const Point2& b)  { return a.p == b.p; }
bool point2_neq(const Point2& a, const Point2& b) { return a.p != b.p; }
bool point2_lt(const Point2& a, const Point2& b)  { return a.p < b.p; }
bool point2_gt(const Point2& a, const Point2& b)  { return a.p > b.p; }
bool point2_le(const Point2& a, const Point2& b)  { return a.p <= b.p; }
bool point2_ge(const Point2& a, const Point2& b)  { return a.p >= b.p; }

// --- Vector2 operations ---
Vector2 vector2_add(const Vector2& a, const Vector2& b) {
    auto result = a.v + b.v;
    return Vector2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Vector2 vector2_sub(const Vector2& a, const Vector2& b) {
    auto result = a.v - b.v;
    return Vector2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Vector2 vector2_mul(const Vector2& a, double scalar) {
    auto result = a.v * scalar;
    return Vector2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Vector2 vector2_neg(const Vector2& v) {
    return Vector2(CGAL::to_double((-v.v).x()), CGAL::to_double((-v.v).y()));
}

// --- Miscellaneous ---
Bbox2 point2_bbox(const Point2& p) {
    auto b = p.p.bbox();
    return Bbox2(b.xmin(), b.ymin(), b.xmax(), b.ymax());
}

Point2 point2_from_weighted(const WeightedPoint2& wp) {
    auto pt = wp.wp.point();
    return Point2(CGAL::to_double(pt.x()), CGAL::to_double(pt.y()));
}