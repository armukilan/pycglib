#include "core/tetrahedron3.h"

bool tetra3_eq(const Tetrahedron3& a, const Tetrahedron3& b) {
    return a.t == b.t;
}

bool tetra3_neq(const Tetrahedron3& a, const Tetrahedron3& b) {
    return a.t != b.t;
}

Point3 tetra3_vertex(const Tetrahedron3& t, int i) {
    auto v = t.t.vertex(i);
    return Point3(CGAL::to_double(v.x()),
                  CGAL::to_double(v.y()),
                  CGAL::to_double(v.z()));
}

bool tetra3_is_degenerate(const Tetrahedron3& t) {
    return t.t.is_degenerate();
}

int tetra3_orientation(const Tetrahedron3& t) {
    auto o = t.t.orientation();
    if (o == CGAL::COUNTERCLOCKWISE) return 1;
    if (o == CGAL::CLOCKWISE)        return -1;
    return 0;
}

int tetra3_oriented_side(const Tetrahedron3& t, const Point3& p) {
    auto side = t.t.oriented_side(CGALPoint3(p.x(), p.y(), p.z()));
    if (side == CGAL::ON_POSITIVE_SIDE) return 1;
    if (side == CGAL::ON_NEGATIVE_SIDE) return -1;
    return 0;
}

int tetra3_bounded_side(const Tetrahedron3& t, const Point3& p) {
    auto side = t.t.bounded_side(CGALPoint3(p.x(), p.y(), p.z()));
    if (side == CGAL::ON_BOUNDED_SIDE)   return 1;
    if (side == CGAL::ON_UNBOUNDED_SIDE) return -1;
    return 0;
}

bool tetra3_has_on_positive_side(const Tetrahedron3& t, const Point3& p) {
    return t.t.has_on_positive_side(CGALPoint3(p.x(), p.y(), p.z()));
}

bool tetra3_has_on_negative_side(const Tetrahedron3& t, const Point3& p) {
    return t.t.has_on_negative_side(CGALPoint3(p.x(), p.y(), p.z()));
}

bool tetra3_has_on_boundary(const Tetrahedron3& t, const Point3& p) {
    return t.t.has_on_boundary(CGALPoint3(p.x(), p.y(), p.z()));
}

bool tetra3_has_on_bounded_side(const Tetrahedron3& t, const Point3& p) {
    return t.t.has_on_bounded_side(CGALPoint3(p.x(), p.y(), p.z()));
}

bool tetra3_has_on_unbounded_side(const Tetrahedron3& t, const Point3& p) {
    return t.t.has_on_unbounded_side(CGALPoint3(p.x(), p.y(), p.z()));
}

double tetra3_volume(const Tetrahedron3& t) {
    return CGAL::to_double(t.t.volume());
}

Bbox3 tetra3_bbox(const Tetrahedron3& t) {
    auto b = t.t.bbox();
    return Bbox3(b.xmin(), b.ymin(), b.zmin(),
                 b.xmax(), b.ymax(), b.zmax());
}