#include "core/circle3.h"

bool circle3_eq(const Circle3& a, const Circle3& b) { return a.c == b.c; }
bool circle3_neq(const Circle3& a, const Circle3& b) { return a.c != b.c; }

Point3 circle3_center(const Circle3& c) {
    auto ct = c.c.center();
    return Point3(CGAL::to_double(ct.x()),
                  CGAL::to_double(ct.y()),
                  CGAL::to_double(ct.z()));
}

double circle3_squared_radius(const Circle3& c) {
    return CGAL::to_double(c.c.squared_radius());
}

Plane3 circle3_supporting_plane(const Circle3& c) {
    return Plane3(c.c.supporting_plane());
}

Sphere3 circle3_diametral_sphere(const Circle3& c) {
    return Sphere3(c.c.diametral_sphere());
}

double circle3_area_divided_by_pi(const Circle3& c) {
    return CGAL::to_double(c.c.area_divided_by_pi());
}

double circle3_approximate_area(const Circle3& c) {
    return c.c.approximate_area();
}

double circle3_squared_length_divided_by_pi_square(const Circle3& c) {
    return CGAL::to_double(c.c.squared_length_divided_by_pi_square());
}

double circle3_approximate_squared_length(const Circle3& c) {
    return c.c.approximate_squared_length();
}

bool circle3_has_on(const Circle3& c, const Point3& p) {
    return c.c.has_on(CGALPoint3(p.x(), p.y(), p.z()));
}

Bbox3 circle3_bbox(const Circle3& c) {
    auto b = c.c.bbox();
    return Bbox3(b.xmin(), b.ymin(), b.zmin(),
                 b.xmax(), b.ymax(), b.zmax());
}