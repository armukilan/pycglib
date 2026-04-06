#include "core/weighted_point3.h"

Point3 wp3_point(const WeightedPoint3& wp) {
    auto p = wp.wp.point();
    return Point3(CGAL::to_double(p.x()),
                  CGAL::to_double(p.y()),
                  CGAL::to_double(p.z()));
}

double wp3_weight(const WeightedPoint3& wp) {
    return CGAL::to_double(wp.wp.weight());
}

bool wp3_eq(const WeightedPoint3& a, const WeightedPoint3& b) {
    return a.wp == b.wp;
}

bool wp3_neq(const WeightedPoint3& a, const WeightedPoint3& b) {
    return a.wp != b.wp;
}