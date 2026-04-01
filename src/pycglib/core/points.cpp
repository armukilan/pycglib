#include "core/points.h"

// --- Point2 operations ---
Vector2 point2_sub(const Point2& a, const Point2& b) {
    auto result = a.p - b.p;
    return Vector2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Vector2 vector2_add(const Vector2& a, const Vector2& b) {
    auto result = a.v + b.v;
    return Vector2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Vector2 vector2_mul(const Vector2& a, double scalar) {
    auto result = a.v * scalar;
    return Vector2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}

Point2 point2_add_vector(const Point2& p, const Vector2& vec) {
    auto result = p.p + vec.v;
    return Point2(CGAL::to_double(result.x()), CGAL::to_double(result.y()));
}