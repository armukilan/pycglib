#include "core/triangle3.h"

bool triangle3_eq(const Triangle3& a, const Triangle3& b) {
    return a.t == b.t;
}

bool triangle3_neq(const Triangle3& a, const Triangle3& b) {
    return a.t != b.t;
}

Point3 triangle3_vertex(const Triangle3& t, int i) {
    auto v = t.t.vertex(i);
    return Point3(CGAL::to_double(v.x()),
                  CGAL::to_double(v.y()),
                  CGAL::to_double(v.z()));
}

Plane3 triangle3_supporting_plane(const Triangle3& t) {
    return Plane3(t.t.supporting_plane());
}

bool triangle3_is_degenerate(const Triangle3& t) {
    return t.t.is_degenerate();
}

bool triangle3_has_on(const Triangle3& t, const Point3& p) {
    return t.t.has_on(CGALPoint3(p.x(), p.y(), p.z()));
}

double triangle3_squared_area(const Triangle3& t) {
    return CGAL::to_double(t.t.squared_area());
}

Bbox3 triangle3_bbox(const Triangle3& t) {
    auto b = t.t.bbox();
    return Bbox3(b.xmin(), b.ymin(), b.zmin(),
                 b.xmax(), b.ymax(), b.zmax());
}