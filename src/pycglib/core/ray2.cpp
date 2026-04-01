#include "core/ray2.h"

// --- Operations ---
bool ray2_eq(const Ray2& a, const Ray2& b) {
    return a.r == b.r;
}

bool ray2_neq(const Ray2& a, const Ray2& b) {
    return a.r != b.r;
}

Point2 ray2_source(const Ray2& r) {
    auto s = r.r.source();
    return Point2(CGAL::to_double(s.x()), CGAL::to_double(s.y()));
}

Point2 ray2_point(const Ray2& r, double i) {
    auto p = r.r.point(i);
    return Point2(CGAL::to_double(p.x()), CGAL::to_double(p.y()));
}

Direction2 ray2_direction(const Ray2& r) {
    return Direction2(r.r.direction());
}

Vector2 ray2_to_vector(const Ray2& r) {
    auto v = r.r.to_vector();
    return Vector2(CGAL::to_double(v.x()), CGAL::to_double(v.y()));
}

Line2 ray2_supporting_line(const Ray2& r) {
    return Line2(r.r.supporting_line());
}

Ray2 ray2_opposite(const Ray2& r) {
    return Ray2(r.r.opposite());
}

// --- Predicates ---
bool ray2_is_degenerate(const Ray2& r) {
    return r.r.is_degenerate();
}

bool ray2_is_horizontal(const Ray2& r) {
    return r.r.is_horizontal();
}

bool ray2_is_vertical(const Ray2& r) {
    return r.r.is_vertical();
}

bool ray2_has_on(const Ray2& r, const Point2& p) {
    return r.r.has_on(CGALPoint2(p.x(), p.y()));
}

bool ray2_collinear_has_on(const Ray2& r, const Point2& p) {
    return r.r.collinear_has_on(CGALPoint2(p.x(), p.y()));
}