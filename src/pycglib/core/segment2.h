#pragma once
#include <CGAL/Simple_cartesian.h>
#include "core/points.h"

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Segment_2  CGALSegment2;
typedef Kernel::Line_2     CGALLine2;
typedef Kernel::Direction_2 CGALDirection2;
typedef Kernel::Vector_2   CGALVector2;

// Forward declare Line2 and Direction2 — full types come later
struct Direction2 {
    CGALDirection2 d;
    Direction2(CGALDirection2 dir) : d(dir) {}
    double dx() const { return CGAL::to_double(d.dx()); }
    double dy() const { return CGAL::to_double(d.dy()); }
};

struct Line2 {
    CGALLine2 l;
    Line2(CGALLine2 line) : l(line) {}
    double a() const { return CGAL::to_double(l.a()); }
    double b() const { return CGAL::to_double(l.b()); }
    double c() const { return CGAL::to_double(l.c()); }
};

struct Bbox2 {
    double xmin, ymin, xmax, ymax;
    Bbox2(double xmin, double ymin, double xmax, double ymax)
        : xmin(xmin), ymin(ymin), xmax(xmax), ymax(ymax) {}
};

struct Segment2 {
    CGALSegment2 s;
    Segment2(const Point2& p, const Point2& q)
        : s(CGALPoint2(p.x(), p.y()), CGALPoint2(q.x(), q.y())) {}
    Segment2(CGALSegment2 seg) : s(seg) {}
};

// --- Creation ---
Segment2 make_segment2(const Point2& p, const Point2& q);

// --- Operations ---
bool     segment2_eq(const Segment2& a, const Segment2& b);
bool     segment2_neq(const Segment2& a, const Segment2& b);
Point2   segment2_source(const Segment2& s);
Point2   segment2_target(const Segment2& s);
Point2   segment2_min(const Segment2& s);
Point2   segment2_max(const Segment2& s);
Point2   segment2_vertex(const Segment2& s, int i);
Point2   segment2_point(const Segment2& s, int i);
double   segment2_squared_length(const Segment2& s);
Direction2 segment2_direction(const Segment2& s);
Vector2  segment2_to_vector(const Segment2& s);
Segment2 segment2_opposite(const Segment2& s);
Line2    segment2_supporting_line(const Segment2& s);

// --- Predicates ---
bool segment2_is_degenerate(const Segment2& s);
bool segment2_is_horizontal(const Segment2& s);
bool segment2_is_vertical(const Segment2& s);
bool segment2_has_on(const Segment2& s, const Point2& p);
bool segment2_collinear_has_on(const Segment2& s, const Point2& p);

// --- Miscellaneous ---
Bbox2    segment2_bbox(const Segment2& s);