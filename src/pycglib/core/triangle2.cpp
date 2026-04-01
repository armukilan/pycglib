#include "core/triangle2.h"

// --- Operations ---
bool triangle2_eq(const Triangle2& a, const Triangle2& b) {
    return a.t == b.t;
}

bool triangle2_neq(const Triangle2& a, const Triangle2& b) {
    return a.t != b.t;
}

Point2 triangle2_vertex(const Triangle2& t, int i) {
    auto v = t.t.vertex(i);
    return Point2(CGAL::to_double(v.x()), CGAL::to_double(v.y()));
}

// --- Predicates ---
bool triangle2_is_degenerate(const Triangle2& t) {
    return t.t.is_degenerate();
}

int triangle2_orientation(const Triangle2& t) {
    auto o = t.t.orientation();
    if (o == CGAL::COUNTERCLOCKWISE) return 1;
    if (o == CGAL::CLOCKWISE)        return -1;
    return 0;
}

int triangle2_oriented_side(const Triangle2& t, const Point2& p) {
    auto side = t.t.oriented_side(CGALPoint2(p.x(), p.y()));
    if (side == CGAL::ON_POSITIVE_SIDE)   return 1;
    if (side == CGAL::ON_NEGATIVE_SIDE)   return -1;
    return 0;
}

int triangle2_bounded_side(const Triangle2& t, const Point2& p) {
    auto side = t.t.bounded_side(CGALPoint2(p.x(), p.y()));
    if (side == CGAL::ON_BOUNDED_SIDE)   return 1;
    if (side == CGAL::ON_UNBOUNDED_SIDE) return -1;
    return 0;
}

bool triangle2_has_on_positive_side(const Triangle2& t, const Point2& p) {
    return t.t.has_on_positive_side(CGALPoint2(p.x(), p.y()));
}

bool triangle2_has_on_negative_side(const Triangle2& t, const Point2& p) {
    return t.t.has_on_negative_side(CGALPoint2(p.x(), p.y()));
}

bool triangle2_has_on_boundary(const Triangle2& t, const Point2& p) {
    return t.t.has_on_boundary(CGALPoint2(p.x(), p.y()));
}

bool triangle2_has_on_bounded_side(const Triangle2& t, const Point2& p) {
    return t.t.has_on_bounded_side(CGALPoint2(p.x(), p.y()));
}

bool triangle2_has_on_unbounded_side(const Triangle2& t, const Point2& p) {
    return t.t.has_on_unbounded_side(CGALPoint2(p.x(), p.y()));
}

// --- Miscellaneous ---
Triangle2 triangle2_opposite(const Triangle2& t) {
    return Triangle2(t.t.opposite());
}

double triangle2_area(const Triangle2& t) {
    return CGAL::to_double(t.t.area());
}

Bbox2 triangle2_bbox(const Triangle2& t) {
    auto b = t.t.bbox();
    return Bbox2(b.xmin(), b.ymin(), b.xmax(), b.ymax());
}