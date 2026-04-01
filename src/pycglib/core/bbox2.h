#pragma once
#include "core/types.h"

// --- Operations ---
bool  bbox2_eq(const Bbox2& a, const Bbox2& b);
bool  bbox2_neq(const Bbox2& a, const Bbox2& b);
int   bbox2_dimension(const Bbox2& b);
double bbox2_min(const Bbox2& b, int i);
double bbox2_max(const Bbox2& b, int i);
Bbox2 bbox2_add(const Bbox2& a, const Bbox2& b);
Bbox2 bbox2_iadd(Bbox2& a, const Bbox2& b);
void  bbox2_dilate(Bbox2& b, int dist);
void  bbox2_scale(Bbox2& b, double factor);
bool  bbox2_do_overlap(const Bbox2& a, const Bbox2& b);