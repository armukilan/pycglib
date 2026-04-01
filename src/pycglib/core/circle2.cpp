#include "core/circle2.h"

// --- Access ---
bool circle2_eq(const Circle2& a, const Circle2& b) {
    return a.c == b.c;
}

bool circle2_neq(const Circle2& a, const Circle2& b) {
    return a.c != b.c;
}

Point2 circle2_center(const Circle2& c) {
    auto ct = c.c.center();
    return Point2(CGAL::to_double(ct.x()), CGAL::to_double(ct.y()));
}

double circle2_squared_radius(const Circle2& c) {
    return CGAL::to_double(c.c.squared_radius());
}

int circle2_orientation(const Circle2& c) {
    auto o = c.c.orientation();
    if (o == CGAL::COUNTERCLOCKWISE) return 1;
    if (o == CGAL::CLOCKWISE)        return -1;
    return 0;
}

// --- Predicates ---
bool circle2_is_degenerate(const Circle2& c) {
    return c.c.is_degenerate();
}

int circle2_oriented_side(const Circle2& c, const Point2& p) {
    auto side = c.c.oriented_side(CGALPoint2(p.x(), p.y()));
    if (side == CGAL::ON_POSITIVE_SIDE) return 1;
    if (side == CGAL::ON_NEGATIVE_SIDE) return -1;
    return 0;
}

int circle2_bounded_side(const Circle2& c, const Point2& p) {
    auto side = c.c.bounded_side(CGALPoint2(p.x(), p.y()));
    if (side == CGAL::ON_BOUNDED_SIDE)   return 1;
    if (side == CGAL::ON_UNBOUNDED_SIDE) return -1;
    return 0;
}

bool circle2_has_on_positive_side(const Circle2& c, const Point2& p) {
    return c.c.has_on_positive_side(CGALPoint2(p.x(), p.y()));
}

bool circle2_has_on_negative_side(const Circle2& c, const Point2& p) {
    return c.c.has_on_negative_side(CGALPoint2(p.x(), p.y()));
}

bool circle2_has_on_boundary(const Circle2& c, const Point2& p) {
    return c.c.has_on_boundary(CGALPoint2(p.x(), p.y()));
}

bool circle2_has_on_bounded_side(const Circle2& c, const Point2& p) {
    return c.c.has_on_bounded_side(CGALPoint2(p.x(), p.y()));
}

bool circle2_has_on_unbounded_side(const Circle2& c, const Point2& p) {
    return c.c.has_on_unbounded_side(CGALPoint2(p.x(), p.y()));
}

// --- Miscellaneous ---
Circle2 circle2_opposite(const Circle2& c) {
    return Circle2(c.c.opposite());
}

Bbox2 circle2_bbox(const Circle2& c) {
    auto b = c.c.bbox();
    return Bbox2(b.xmin(), b.ymin(), b.xmax(), b.ymax());
}