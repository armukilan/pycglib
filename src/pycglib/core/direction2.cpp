#include "core/direction2.h"

// --- Creation ---
Direction2 direction2_from_vector(const Vector2& v) {
    return Direction2(CGALDirection2(v.v));
}

Direction2 direction2_from_segment(const Segment2& s) {
    return Direction2(s.s.direction());
}

Direction2 direction2_from_xy(double x, double y) {
    return Direction2(x, y);
}

// --- Operations ---
bool direction2_eq(const Direction2& a, const Direction2& b) {
    return a.d == b.d;
}

bool direction2_neq(const Direction2& a, const Direction2& b) {
    return a.d != b.d;
}

bool direction2_lt(const Direction2& a, const Direction2& b) {
    return a.d < b.d;
}

bool direction2_gt(const Direction2& a, const Direction2& b) {
    return a.d > b.d;
}

bool direction2_le(const Direction2& a, const Direction2& b) {
    return a.d <= b.d;
}

bool direction2_ge(const Direction2& a, const Direction2& b) {
    return a.d >= b.d;
}

bool direction2_counterclockwise_in_between(const Direction2& d, const Direction2& d1, const Direction2& d2) {
    return d.d.counterclockwise_in_between(d1.d, d2.d);
}

Direction2 direction2_opposite(const Direction2& d) {
    return Direction2(-d.d);
}

// --- Miscellaneous ---
Vector2 direction2_vector(const Direction2& d) {
    auto v = d.d.vector();
    return Vector2(CGAL::to_double(v.x()), CGAL::to_double(v.y()));
}