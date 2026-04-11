#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_2.h>
#include <CGAL/Triangulation_face_base_2.h>
#include <CGAL/Triangulation_data_structure_2.h>
#include <CGAL/Object.h>
#include "core/triangulation2.h"  // shared: T2Kernel, T2Tds, all handle types

namespace py = pybind11;


typedef CGAL::Delaunay_triangulation_2<T2Kernel, T2Tds>   CGALDelaunay2;

struct DelaunayTriangulation2 {
    CGALDelaunay2 dt;
    DelaunayTriangulation2() = default;
};



DelaunayTriangulation2 dt2_create();

void dt2_clear(DelaunayTriangulation2& dt);
void dt2_swap(DelaunayTriangulation2& a, DelaunayTriangulation2& b);
int dt2_dimension(const DelaunayTriangulation2& dt);
int dt2_number_of_vertices(const DelaunayTriangulation2& dt);
int dt2_number_of_faces(const DelaunayTriangulation2& dt);
bool dt2_is_valid(const DelaunayTriangulation2& dt, bool verbose);


// ═══════════════════════════════════════════════════════════════════════════
// SPECIAL VERTICES / FACES
// ═══════════════════════════════════════════════════════════════════════════

VertexHandle2 dt2_infinite_vertex(const DelaunayTriangulation2& dt);
FaceHandle2   dt2_infinite_face(const DelaunayTriangulation2& dt);
VertexHandle2 dt2_finite_vertex(const DelaunayTriangulation2& dt);


// ═══════════════════════════════════════════════════════════════════════════
// INSERT / REMOVE
// These override Triangulation_2 to run Lawson edge-flips after modification.
// ═══════════════════════════════════════════════════════════════════════════

VertexHandle2 dt2_insert_point(DelaunayTriangulation2& dt, const Point2& p);
VertexHandle2 dt2_insert_point_hint(DelaunayTriangulation2& dt, const Point2& p,
                                    const FaceHandle2& hint);
int dt2_insert_points(DelaunayTriangulation2& dt, const std::vector<Point2>& pts);

void dt2_remove(DelaunayTriangulation2& dt, const VertexHandle2& v);
VertexHandle2 dt2_push_back(DelaunayTriangulation2& dt, const Point2& p);


// ═══════════════════════════════════════════════════════════════════════════
// DISPLACEMENT
// ═══════════════════════════════════════════════════════════════════════════


VertexHandle2 dt2_move(DelaunayTriangulation2& dt, const VertexHandle2& v, const Point2& p);


VertexHandle2 dt2_move_if_no_collision(DelaunayTriangulation2& dt,
                                        const VertexHandle2& v, const Point2& p);


// ═══════════════════════════════════════════════════════════════════════════
// NEAREST VERTEX
// ═══════════════════════════════════════════════════════════════════════════


VertexHandle2 dt2_nearest_vertex(const DelaunayTriangulation2& dt, const Point2& p);


VertexHandle2 dt2_nearest_vertex_hint(const DelaunayTriangulation2& dt,
                                       const Point2& p, const FaceHandle2& f);


// ═══════════════════════════════════════════════════════════════════════════
// CONFLICT ZONE
// ═══════════════════════════════════════════════════════════════════════════

std::vector<FaceHandle2> dt2_get_conflicts(const DelaunayTriangulation2& dt,
                                            const Point2& p);
std::vector<EdgeHandle2> dt2_get_boundary_of_conflicts(const DelaunayTriangulation2& dt,
                                                        const Point2& p);
py::tuple dt2_get_conflicts_and_boundary(const DelaunayTriangulation2& dt,
                                          const Point2& p);


// ═══════════════════════════════════════════════════════════════════════════
// VORONOI DIAGRAM — dual functions
// ═══════════════════════════════════════════════════════════════════════════

Point2 dt2_dual_point(const DelaunayTriangulation2& dt, const FaceHandle2& f);
std::string dt2_dual_type(const DelaunayTriangulation2& dt, const EdgeHandle2& e);
py::object dt2_dual_segment(const DelaunayTriangulation2& dt, const EdgeHandle2& e);
py::object dt2_dual_ray(const DelaunayTriangulation2& dt, const EdgeHandle2& e);
py::object dt2_dual_line(const DelaunayTriangulation2& dt, const EdgeHandle2& e);


// ═══════════════════════════════════════════════════════════════════════════
// PREDICATES
// ═══════════════════════════════════════════════════════════════════════════

int dt2_side_of_oriented_circle(const DelaunayTriangulation2& dt,
                                 const FaceHandle2& f, const Point2& p);

// ─── Inherited predicates ─────────────────────────────────────────────────────
bool      dt2_is_infinite_vertex(const DelaunayTriangulation2& dt, const VertexHandle2& v);
bool      dt2_is_infinite_face(const DelaunayTriangulation2& dt, const FaceHandle2& f);
bool      dt2_is_infinite_edge(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i);
bool      dt2_is_edge(const DelaunayTriangulation2& dt, const VertexHandle2& va, const VertexHandle2& vb);
py::tuple dt2_is_edge_full(const DelaunayTriangulation2& dt, const VertexHandle2& va, const VertexHandle2& vb);
bool      dt2_is_face3(const DelaunayTriangulation2& dt, const VertexHandle2& v1,
                       const VertexHandle2& v2, const VertexHandle2& v3);
py::tuple dt2_is_face3_full(const DelaunayTriangulation2& dt, const VertexHandle2& v1,
                             const VertexHandle2& v2, const VertexHandle2& v3);


// ═══════════════════════════════════════════════════════════════════════════
// LOCATE (inherited — identical API to Triangulation2)
// ═══════════════════════════════════════════════════════════════════════════

FaceHandle2 dt2_locate(const DelaunayTriangulation2& dt, const Point2& query);
FaceHandle2 dt2_locate_hint(const DelaunayTriangulation2& dt,
                              const Point2& query, const FaceHandle2& hint);
/** Returns (FaceHandle2, locate_type: int, li: int). Uses T2_* constants. */
py::tuple   dt2_locate_full(const DelaunayTriangulation2& dt, const Point2& query);
FaceHandle2 dt2_inexact_locate(const DelaunayTriangulation2& dt, const Point2& query);


// ═══════════════════════════════════════════════════════════════════════════
// GEOMETRY HELPERS (inherited)
// ═══════════════════════════════════════════════════════════════════════════

Triangle2     dt2_triangle(const DelaunayTriangulation2& dt, const FaceHandle2& f);
Segment2      dt2_segment_face_i(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i);
Segment2      dt2_segment_edge(const DelaunayTriangulation2& dt, const EdgeHandle2& e);
Point2        dt2_circumcenter(const DelaunayTriangulation2& dt, const FaceHandle2& f);
Point2        dt2_point_face_i(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i);
Point2        dt2_point_vertex(const DelaunayTriangulation2& dt, const VertexHandle2& v);
int           dt2_ccw(const DelaunayTriangulation2& dt, int i);
int           dt2_cw(const DelaunayTriangulation2& dt, int i);
int           dt2_oriented_side(const DelaunayTriangulation2& dt, const FaceHandle2& f, const Point2& p);


// ═══════════════════════════════════════════════════════════════════════════
// ADJACENCY (inherited)
// ═══════════════════════════════════════════════════════════════════════════

VertexHandle2 dt2_mirror_vertex(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i);
int           dt2_mirror_index(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i);
EdgeHandle2   dt2_mirror_edge(const DelaunayTriangulation2& dt, const EdgeHandle2& e);


// ═══════════════════════════════════════════════════════════════════════════
// ITERATORS → Python lists
// ═══════════════════════════════════════════════════════════════════════════

std::vector<VertexHandle2> dt2_finite_vertices(const DelaunayTriangulation2& dt);
std::vector<FaceHandle2>   dt2_finite_faces(const DelaunayTriangulation2& dt);
std::vector<EdgeHandle2>   dt2_finite_edges(const DelaunayTriangulation2& dt);
std::vector<Point2>        dt2_points(const DelaunayTriangulation2& dt);
std::vector<VertexHandle2> dt2_all_vertices(const DelaunayTriangulation2& dt);
std::vector<FaceHandle2>   dt2_all_faces(const DelaunayTriangulation2& dt);
std::vector<EdgeHandle2>   dt2_all_edges(const DelaunayTriangulation2& dt);


// ═══════════════════════════════════════════════════════════════════════════
// CIRCULATORS → Python lists
// ═══════════════════════════════════════════════════════════════════════════

std::vector<FaceHandle2>   dt2_incident_faces(const DelaunayTriangulation2& dt, const VertexHandle2& v);
std::vector<EdgeHandle2>   dt2_incident_edges(const DelaunayTriangulation2& dt, const VertexHandle2& v);
std::vector<VertexHandle2> dt2_incident_vertices(const DelaunayTriangulation2& dt, const VertexHandle2& v);
std::vector<FaceHandle2>   dt2_line_walk(const DelaunayTriangulation2& dt, const Point2& p, const Point2& q);


// ═══════════════════════════════════════════════════════════════════════════
// CONVEX HULL
// ═══════════════════════════════════════════════════════════════════════════

std::vector<VertexHandle2> dt2_convex_hull_vertices(const DelaunayTriangulation2& dt);
std::vector<EdgeHandle2>   dt2_convex_hull_edges(const DelaunayTriangulation2& dt);