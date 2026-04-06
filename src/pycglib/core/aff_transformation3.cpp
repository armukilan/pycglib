#include "core/aff_transformation3.h"

Point3 aff3_transform_point(const AffTransformation3& t, const Point3& p) {
    auto r = t.t.transform(CGALPoint3(p.x(), p.y(), p.z()));
    return Point3(CGAL::to_double(r.x()),
                  CGAL::to_double(r.y()),
                  CGAL::to_double(r.z()));
}

Vector3 aff3_transform_vector(const AffTransformation3& t, const Vector3& v) {
    auto r = t.t.transform(v.v);
    return Vector3(CGAL::to_double(r.x()),
                   CGAL::to_double(r.y()),
                   CGAL::to_double(r.z()));
}

Direction3 aff3_transform_direction(const AffTransformation3& t, const Direction3& d) {
    return Direction3(t.t.transform(d.d));
}

Plane3 aff3_transform_plane(const AffTransformation3& t, const Plane3& p) {
    return Plane3(t.t.transform(p.p));
}

AffTransformation3 aff3_mul(const AffTransformation3& a, const AffTransformation3& b) {
    return AffTransformation3(a.t * b.t);
}

AffTransformation3 aff3_inverse(const AffTransformation3& t) {
    return AffTransformation3(t.t.inverse());
}

bool aff3_eq(const AffTransformation3& a, const AffTransformation3& b) {
    return a.t == b.t;
}

bool aff3_is_even(const AffTransformation3& t)        { return t.t.is_even(); }
bool aff3_is_odd(const AffTransformation3& t)         { return t.t.is_odd(); }
bool aff3_is_scaling(const AffTransformation3& t)     { return t.t.is_scaling(); }
bool aff3_is_translation(const AffTransformation3& t) { return t.t.is_translation(); }

double aff3_cartesian(const AffTransformation3& t, int i, int j) {
    return CGAL::to_double(t.t.cartesian(i, j));
}

double aff3_homogeneous(const AffTransformation3& t, int i, int j) {
    return CGAL::to_double(t.t.homogeneous(i, j));
}