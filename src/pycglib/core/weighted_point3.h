#pragma once
#include "core/types.h"

// --- Bare point and weight accessors ---
Point3 wp3_point(const WeightedPoint3& wp);
double wp3_weight(const WeightedPoint3& wp);

// --- Operations ---
bool wp3_eq(const WeightedPoint3& a, const WeightedPoint3& b);
bool wp3_neq(const WeightedPoint3& a, const WeightedPoint3& b);