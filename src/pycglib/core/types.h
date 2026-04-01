#pragma once
#include <CGAL/Simple_cartesian.h>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2      CGALPoint2;
typedef Kernel::Vector_2     CGALVector2;
typedef Kernel::Direction_2  CGALDirection2;
typedef Kernel::Segment_2    CGALSegment2;
typedef Kernel::Line_2       CGALLine2;

// ─── Point2 ───────────────────────────────────────────────
struct Point2 {
    CGALPoint2 p;
    Point2(double x, double y) : p(x, y) {}
    Point2(CGALPoint2 pt) : p(pt) {}
    double x() const { return CGAL::to_double(p.x()); }
    double y() const { return CGAL::to_double(p.y()); }
};

// ─── Vector2 ──────────────────────────────────────────────
struct Vector2 {
    CGALVector2 v;
    Vector2(double x, double y) : v(x, y) {}
    Vector2(CGALVector2 vec) : v(vec) {}
    double x() const { return CGAL::to_double(v.x()); }
    double y() const { return CGAL::to_double(v.y()); }
};

// ─── Direction2 ───────────────────────────────────────────
struct Direction2 {
    CGALDirection2 d;
    Direction2(double x, double y) : d(x, y) {}
    Direction2(CGALDirection2 dir) : d(dir) {}
    double dx()       const { return CGAL::to_double(d.dx()); }
    double dy()       const { return CGAL::to_double(d.dy()); }
    double delta(int i) const { return CGAL::to_double(d.delta(i)); }
};

// ─── Bbox2 ────────────────────────────────────────────────
struct Bbox2 {
    double xmin, ymin, xmax, ymax;
    Bbox2(double xmin, double ymin, double xmax, double ymax)
        : xmin(xmin), ymin(ymin), xmax(xmax), ymax(ymax) {}
};

// ─── Line2 (stub — full impl later) ──────────────────────
struct Line2 {
    CGALLine2 l;
    Line2(CGALLine2 line) : l(line) {}
    double a() const { return CGAL::to_double(l.a()); }
    double b() const { return CGAL::to_double(l.b()); }
    double c() const { return CGAL::to_double(l.c()); }
};

// ─── Segment2 ─────────────────────────────────────────────
struct Segment2 {
    CGALSegment2 s;
    Segment2(const Point2& p, const Point2& q)
        : s(CGALPoint2(p.x(), p.y()), CGALPoint2(q.x(), q.y())) {}
    Segment2(CGALSegment2 seg) : s(seg) {}
};