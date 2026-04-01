#include "core/segment2.h"
#include "core/direction2.h"

// --- Creation ---
Segment2 make_segment2(const Point2& p, const Point2& q) {
    return Segment2(p, q);
}

// --- Operations ---
bool segment2_eq(const Segment2& a, const Segment2& b) {
    return a.s == b.s;
}

bool segment2_neq(const Segment2& a, const Segment2& b) {
    return a.s != b.s;
}

Point2 segment2_source(const Segment2& s) {
    return Point2(CGAL::to_double(s.s.source().x()),
                  CGAL::to_double(s.s.source().y()));
}

Point2 segment2_target(const Segment2& s) {
    return Point2(CGAL::to_double(s.s.target().x()),
                  CGAL::to_double(s.s.target().y()));
}

Point2 segment2_min(const Segment2& s) {
    return Point2(CGAL::to_double(s.s.min().x()),
                  CGAL::to_double(s.s.min().y()));
}

Point2 segment2_max(const Segment2& s) {
    return Point2(CGAL::to_double(s.s.max().x()),
                  CGAL::to_double(s.s.max().y()));
}

Point2 segment2_vertex(const Segment2& s, int i) {
    auto v = s.s.vertex(i);
    return Point2(CGAL::to_double(v.x()), CGAL::to_double(v.y()));
}

Point2 segment2_point(const Segment2& s, int i) {
    auto v = s.s.point(i);
    return Point2(CGAL::to_double(v.x()), CGAL::to_double(v.y()));
}

double segment2_squared_length(const Segment2& s) {
    return CGAL::to_double(s.s.squared_length());
}

Direction2 segment2_direction(const Segment2& s) {
    return Direction2(s.s.direction());
}

Vector2 segment2_to_vector(const Segment2& s) {
    auto v = s.s.to_vector();
    return Vector2(CGAL::to_double(v.x()), CGAL::to_double(v.y()));
}

Segment2 segment2_opposite(const Segment2& s) {
    return Segment2(s.s.opposite());
}

Line2 segment2_supporting_line(const Segment2& s) {
    return Line2(s.s.supporting_line());
}

// --- Predicates ---
bool segment2_is_degenerate(const Segment2& s) {
    return s.s.is_degenerate();
}

bool segment2_is_horizontal(const Segment2& s) {
    return s.s.is_horizontal();
}

bool segment2_is_vertical(const Segment2& s) {
    return s.s.is_vertical();
}

bool segment2_has_on(const Segment2& s, const Point2& p) {
    return s.s.has_on(CGALPoint2(p.x(), p.y()));
}

bool segment2_collinear_has_on(const Segment2& s, const Point2& p) {
    return s.s.collinear_has_on(CGALPoint2(p.x(), p.y()));
}

// --- Miscellaneous ---
Bbox2 segment2_bbox(const Segment2& s) {
    auto b = s.s.bbox();
    return Bbox2(b.xmin(), b.ymin(), b.xmax(), b.ymax());
}