#pragma once
#include "core/types.h"

// Forward declarations of Point2/Vector2 operations
Vector2 point2_sub(const Point2& a, const Point2& b);
Vector2 vector2_add(const Vector2& a, const Vector2& b);
Vector2 vector2_mul(const Vector2& a, double scalar);
Point2  point2_add_vector(const Point2& p, const Vector2& vec);