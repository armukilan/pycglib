#include "core/aff_transformation2.h"

// --- Transform operations ---
Point2 aff2_transform_point(const AffTransformation2& t, const Point2& p) {
    auto result = t.t.transform(CGALPoint2(p.x(), p.y()));
    return Point2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Vector2 aff2_transform_vector(const AffTransformation2& t, const Vector2& v) {
    auto result = t.t.transform(v.v);
    return Vector2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Direction2 aff2_transform_direction(const AffTransformation2& t, const Direction2& d) {
    return Direction2(t.t.transform(d.d));
}

Line2 aff2_transform_line(const AffTransformation2& t, const Line2& l) {
    return Line2(t.t.transform(l.l));
}

// --- Miscellaneous ---
AffTransformation2 aff2_mul(const AffTransformation2& a, const AffTransformation2& b) {
    return AffTransformation2(a.t * b.t);
}

AffTransformation2 aff2_inverse(const AffTransformation2& t) {
    return AffTransformation2(t.t.inverse());
}

bool aff2_eq(const AffTransformation2& a, const AffTransformation2& b) {
    return a.t == b.t;
}

bool aff2_is_even(const AffTransformation2& t) {
    return t.t.is_even();
}

bool aff2_is_odd(const AffTransformation2& t) {
    return t.t.is_odd();
}

bool aff2_is_scaling(const AffTransformation2& t) {
    return t.t.is_scaling();
}

bool aff2_is_translation(const AffTransformation2& t) {
    return t.t.is_translation();
}

bool aff2_is_rotation(const AffTransformation2& t) {
    return t.t.is_rotation();
}

bool aff2_is_reflection(const AffTransformation2& t) {
    return t.t.is_reflection();
}

// --- Matrix entry access ---
double aff2_cartesian(const AffTransformation2& t, int i, int j) {
    return CGAL::to_double(t.t.cartesian(i, j));
}

double aff2_homogeneous(const AffTransformation2& t, int i, int j) {
    return CGAL::to_double(t.t.homogeneous(i, j));
}