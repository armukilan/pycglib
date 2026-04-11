#include "core/delaunay2.h"
#include <stdexcept>

// ─── Internal helpers ─────────────────────────────────────────────────────────

static inline CGALTPoint2 to_cgal(const Point2& p) {
    return CGALTPoint2(p.x(), p.y());
}
static inline Point2 from_cgal(const CGALTPoint2& p) {
    return Point2(CGAL::to_double(p.x()), CGAL::to_double(p.y()));
}

// Gets the CGAL::Object for a Delaunay edge dual. Used by all dual functions.
static inline CGAL::Object get_dual_obj(const DelaunayTriangulation2& dt,
                                         const EdgeHandle2& e) {
    return dt.dt.dual(CGALDelaunay2::Edge(e.face.fh, e.index));
}


// ═══════════════════════════════════════════════════════════════════════════
// CONSTRUCTION / MANAGEMENT
// ═══════════════════════════════════════════════════════════════════════════

DelaunayTriangulation2 dt2_create() { return DelaunayTriangulation2(); }
void dt2_clear(DelaunayTriangulation2& dt) { dt.dt.clear(); }
void dt2_swap(DelaunayTriangulation2& a, DelaunayTriangulation2& b) { a.dt.swap(b.dt); }
int  dt2_dimension(const DelaunayTriangulation2& dt) { return dt.dt.dimension(); }

int dt2_number_of_vertices(const DelaunayTriangulation2& dt) {
    return static_cast<int>(dt.dt.number_of_vertices());
}
int dt2_number_of_faces(const DelaunayTriangulation2& dt) {
    return static_cast<int>(dt.dt.number_of_faces());
}
bool dt2_is_valid(const DelaunayTriangulation2& dt, bool verbose) {
    // Checks combinatorial validity + empty-circle property for every face.
    return dt.dt.is_valid(verbose);
}


// ═══════════════════════════════════════════════════════════════════════════
// SPECIAL VERTICES / FACES
// ═══════════════════════════════════════════════════════════════════════════

VertexHandle2 dt2_infinite_vertex(const DelaunayTriangulation2& dt) {
    return VertexHandle2(dt.dt.infinite_vertex());
}
FaceHandle2 dt2_infinite_face(const DelaunayTriangulation2& dt) {
    return FaceHandle2(dt.dt.infinite_face());
}
VertexHandle2 dt2_finite_vertex(const DelaunayTriangulation2& dt) {
    return VertexHandle2(dt.dt.finite_vertex());
}


// ═══════════════════════════════════════════════════════════════════════════
// INSERT / REMOVE
// ═══════════════════════════════════════════════════════════════════════════

VertexHandle2 dt2_insert_point(DelaunayTriangulation2& dt, const Point2& p) {
    // locate → split → Lawson flips until empty-circle holds everywhere.
    return VertexHandle2(dt.dt.insert(to_cgal(p)));
}
VertexHandle2 dt2_insert_point_hint(DelaunayTriangulation2& dt, const Point2& p,
                                    const FaceHandle2& hint) {
    return VertexHandle2(dt.dt.insert(to_cgal(p), hint.fh));
}
int dt2_insert_points(DelaunayTriangulation2& dt, const std::vector<Point2>& pts) {
    // CGAL calls spatial_sort() — insertion order not preserved.
    std::vector<CGALTPoint2> cpts;
    cpts.reserve(pts.size());
    for (const auto& p : pts) cpts.push_back(to_cgal(p));
    return static_cast<int>(dt.dt.insert(cpts.begin(), cpts.end()));
}
void dt2_remove(DelaunayTriangulation2& dt, const VertexHandle2& v) {
    dt.dt.remove(v.vh);
}
VertexHandle2 dt2_push_back(DelaunayTriangulation2& dt, const Point2& p) {
    return VertexHandle2(dt.dt.push_back(to_cgal(p)));
}


// ═══════════════════════════════════════════════════════════════════════════
// DISPLACEMENT
// ═══════════════════════════════════════════════════════════════════════════

VertexHandle2 dt2_move(DelaunayTriangulation2& dt, const VertexHandle2& v, const Point2& p) {
    return VertexHandle2(dt.dt.move(v.vh, to_cgal(p)));
}
VertexHandle2 dt2_move_if_no_collision(DelaunayTriangulation2& dt,
                                        const VertexHandle2& v, const Point2& p) {
    return VertexHandle2(dt.dt.move_if_no_collision(v.vh, to_cgal(p)));
}


// ═══════════════════════════════════════════════════════════════════════════
// NEAREST VERTEX
// ═══════════════════════════════════════════════════════════════════════════

VertexHandle2 dt2_nearest_vertex(const DelaunayTriangulation2& dt, const Point2& p) {
    // Remembering stochastic walk: locate face containing p, then check
    // incident vertices moving toward the closest one. O(1) average.
    return VertexHandle2(dt.dt.nearest_vertex(to_cgal(p)));
}
VertexHandle2 dt2_nearest_vertex_hint(const DelaunayTriangulation2& dt,
                                       const Point2& p, const FaceHandle2& f) {
    return VertexHandle2(dt.dt.nearest_vertex(to_cgal(p), f.fh));
}


// ═══════════════════════════════════════════════════════════════════════════
// CONFLICT ZONE
// ═══════════════════════════════════════════════════════════════════════════

std::vector<FaceHandle2> dt2_get_conflicts(const DelaunayTriangulation2& dt,
                                            const Point2& p) {
    std::vector<CGALDelaunay2::Face_handle> raw;
    dt.dt.get_conflicts(to_cgal(p), std::back_inserter(raw));
    std::vector<FaceHandle2> out;
    out.reserve(raw.size());
    for (const auto& fh : raw) out.emplace_back(fh);
    return out;
}

std::vector<EdgeHandle2> dt2_get_boundary_of_conflicts(const DelaunayTriangulation2& dt,
                                                        const Point2& p) {
    // Edges are from the NON-conflicting face's perspective, in CCW order.
    std::vector<CGALDelaunay2::Edge> raw;
    dt.dt.get_boundary_of_conflicts(to_cgal(p), std::back_inserter(raw));
    std::vector<EdgeHandle2> out;
    out.reserve(raw.size());
    for (const auto& e : raw)
        out.emplace_back(FaceHandle2(e.first), e.second);
    return out;
}

py::tuple dt2_get_conflicts_and_boundary(const DelaunayTriangulation2& dt,
                                          const Point2& p) {
    // Single traversal — more efficient than two separate calls.
    std::vector<CGALDelaunay2::Face_handle> raw_f;
    std::vector<CGALDelaunay2::Edge>        raw_e;
    dt.dt.get_conflicts_and_boundary(
        to_cgal(p),
        std::back_inserter(raw_f),
        std::back_inserter(raw_e)
    );
    std::vector<FaceHandle2> faces;
    faces.reserve(raw_f.size());
    for (const auto& fh : raw_f) faces.emplace_back(fh);
    std::vector<EdgeHandle2> edges;
    edges.reserve(raw_e.size());
    for (const auto& e : raw_e) edges.emplace_back(FaceHandle2(e.first), e.second);
    return py::make_tuple(faces, edges);
}


// ═══════════════════════════════════════════════════════════════════════════
// VORONOI DIAGRAM — dual functions
// ═══════════════════════════════════════════════════════════════════════════

Point2 dt2_dual_point(const DelaunayTriangulation2& dt, const FaceHandle2& f) {
    // dt.dual(face) returns the circumcenter as Point_2.
    return from_cgal(dt.dt.dual(f.fh));
}

std::string dt2_dual_type(const DelaunayTriangulation2& dt, const EdgeHandle2& e) {
    // Try each CGAL type in order of frequency: segment (interior edges most
    // common), then ray (hull edges), then line (degenerate collinear case).
    CGAL::Object obj = get_dual_obj(dt, e);
    T2Kernel::Segment_2 seg;
    if (CGAL::assign(seg, obj)) return "segment";
    T2Kernel::Ray_2 ray;
    if (CGAL::assign(ray, obj)) return "ray";
    T2Kernel::Line_2 line;
    if (CGAL::assign(line, obj)) return "line";
    return "unknown";  // never reached for a valid 2D triangulation
}

py::object dt2_dual_segment(const DelaunayTriangulation2& dt, const EdgeHandle2& e) {
    // Returns Segment2 for interior edges (both adjacent faces finite).
    // Returns None for hull edges (ray) and degenerate edges (line).
    T2Kernel::Segment_2 seg;
    if (CGAL::assign(seg, get_dual_obj(dt, e)))
        return py::cast(Segment2(from_cgal(seg.source()), from_cgal(seg.target())));
    return py::none();
}

py::object dt2_dual_ray(const DelaunayTriangulation2& dt, const EdgeHandle2& e) {
    // Returns Ray2 for hull edges (exactly one finite adjacent face).
    // The ray starts at the circumcenter of the finite face.
    // Returns None for interior edges (segment) and degenerate edges (line).
    T2Kernel::Ray_2 ray;
    if (CGAL::assign(ray, get_dual_obj(dt, e))) {
        Point2  src(CGAL::to_double(ray.source().x()),
                    CGAL::to_double(ray.source().y()));
        Vector2 dir(CGAL::to_double(ray.direction().dx()),
                    CGAL::to_double(ray.direction().dy()));
        return py::cast(Ray2(src, dir));
    }
    return py::none();
}

py::object dt2_dual_line(const DelaunayTriangulation2& dt, const EdgeHandle2& e) {
    // Returns Line2 only for collinear (1D) triangulations where both
    // adjacent faces are infinite. Returns None for all normal 2D cases.
    T2Kernel::Line_2 line;
    if (CGAL::assign(line, get_dual_obj(dt, e)))
        return py::cast(Line2(CGAL::to_double(line.a()),
                              CGAL::to_double(line.b()),
                              CGAL::to_double(line.c())));
    return py::none();
}


// ═══════════════════════════════════════════════════════════════════════════
// PREDICATES
// ═══════════════════════════════════════════════════════════════════════════

int dt2_side_of_oriented_circle(const DelaunayTriangulation2& dt,
                                 const FaceHandle2& f, const Point2& p) {
    auto s = dt.dt.side_of_oriented_circle(f.fh, to_cgal(p));
    if (s == CGAL::ON_POSITIVE_SIDE) return  1;
    if (s == CGAL::ON_NEGATIVE_SIDE) return -1;
    return 0;
}
bool dt2_is_infinite_vertex(const DelaunayTriangulation2& dt, const VertexHandle2& v) {
    return dt.dt.is_infinite(v.vh);
}
bool dt2_is_infinite_face(const DelaunayTriangulation2& dt, const FaceHandle2& f) {
    return dt.dt.is_infinite(f.fh);
}
bool dt2_is_infinite_edge(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i) {
    return dt.dt.is_infinite(f.fh, i);
}
bool dt2_is_edge(const DelaunayTriangulation2& dt, const VertexHandle2& va, const VertexHandle2& vb) {
    return dt.dt.is_edge(va.vh, vb.vh);
}
py::tuple dt2_is_edge_full(const DelaunayTriangulation2& dt, const VertexHandle2& va, const VertexHandle2& vb) {
    CGALDelaunay2::Face_handle fr; int i;
    bool r = dt.dt.is_edge(va.vh, vb.vh, fr, i);
    return py::make_tuple(r, FaceHandle2(fr), i);
}
bool dt2_is_face3(const DelaunayTriangulation2& dt, const VertexHandle2& v1,
                  const VertexHandle2& v2, const VertexHandle2& v3) {
    return dt.dt.is_face(v1.vh, v2.vh, v3.vh);
}
py::tuple dt2_is_face3_full(const DelaunayTriangulation2& dt, const VertexHandle2& v1,
                             const VertexHandle2& v2, const VertexHandle2& v3) {
    CGALDelaunay2::Face_handle fr;
    bool r = dt.dt.is_face(v1.vh, v2.vh, v3.vh, fr);
    return py::make_tuple(r, FaceHandle2(fr));
}


// ═══════════════════════════════════════════════════════════════════════════
// LOCATE
// ═══════════════════════════════════════════════════════════════════════════

FaceHandle2 dt2_locate(const DelaunayTriangulation2& dt, const Point2& q) {
    return FaceHandle2(dt.dt.locate(to_cgal(q)));
}
FaceHandle2 dt2_locate_hint(const DelaunayTriangulation2& dt,
                              const Point2& q, const FaceHandle2& h) {
    return FaceHandle2(dt.dt.locate(to_cgal(q), h.fh));
}
py::tuple dt2_locate_full(const DelaunayTriangulation2& dt, const Point2& q) {
    CGALDelaunay2::Locate_type lt; int li;
    auto fh = dt.dt.locate(to_cgal(q), lt, li);
    return py::make_tuple(FaceHandle2(fh), static_cast<int>(lt), li);
}
FaceHandle2 dt2_inexact_locate(const DelaunayTriangulation2& dt, const Point2& q) {
    return FaceHandle2(dt.dt.inexact_locate(to_cgal(q)));
}


// ═══════════════════════════════════════════════════════════════════════════
// GEOMETRY HELPERS
// ═══════════════════════════════════════════════════════════════════════════

Triangle2 dt2_triangle(const DelaunayTriangulation2& dt, const FaceHandle2& f) {
    auto tri = dt.dt.triangle(f.fh);
    return Triangle2(
        Point2(CGAL::to_double(tri[0].x()), CGAL::to_double(tri[0].y())),
        Point2(CGAL::to_double(tri[1].x()), CGAL::to_double(tri[1].y())),
        Point2(CGAL::to_double(tri[2].x()), CGAL::to_double(tri[2].y()))
    );
}
Segment2 dt2_segment_face_i(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i) {
    auto seg = dt.dt.segment(f.fh, i);
    return Segment2(from_cgal(seg.source()), from_cgal(seg.target()));
}
Segment2 dt2_segment_edge(const DelaunayTriangulation2& dt, const EdgeHandle2& e) {
    auto seg = dt.dt.segment(CGALDelaunay2::Edge(e.face.fh, e.index));
    return Segment2(from_cgal(seg.source()), from_cgal(seg.target()));
}
Point2 dt2_circumcenter(const DelaunayTriangulation2& dt, const FaceHandle2& f) {
    return from_cgal(dt.dt.circumcenter(f.fh));
}
Point2 dt2_point_face_i(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i) {
    return from_cgal(dt.dt.point(f.fh, i));
}
Point2 dt2_point_vertex(const DelaunayTriangulation2& dt, const VertexHandle2& v) {
    return from_cgal(dt.dt.point(v.vh));
}
int dt2_ccw(const DelaunayTriangulation2& dt, int i) { return dt.dt.ccw(i); }
int dt2_cw(const DelaunayTriangulation2& dt, int i)  { return dt.dt.cw(i); }
int dt2_oriented_side(const DelaunayTriangulation2& dt, const FaceHandle2& f, const Point2& p) {
    auto s = dt.dt.oriented_side(f.fh, to_cgal(p));
    if (s == CGAL::ON_POSITIVE_SIDE) return  1;
    if (s == CGAL::ON_NEGATIVE_SIDE) return -1;
    return 0;
}


// ═══════════════════════════════════════════════════════════════════════════
// ADJACENCY
// ═══════════════════════════════════════════════════════════════════════════

VertexHandle2 dt2_mirror_vertex(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i) {
    return VertexHandle2(dt.dt.mirror_vertex(f.fh, i));
}
int dt2_mirror_index(const DelaunayTriangulation2& dt, const FaceHandle2& f, int i) {
    return dt.dt.mirror_index(f.fh, i);
}
EdgeHandle2 dt2_mirror_edge(const DelaunayTriangulation2& dt, const EdgeHandle2& e) {
    auto me = dt.dt.mirror_edge(CGALDelaunay2::Edge(e.face.fh, e.index));
    return EdgeHandle2(FaceHandle2(me.first), me.second);
}


// ═══════════════════════════════════════════════════════════════════════════
// ITERATORS
// ═══════════════════════════════════════════════════════════════════════════

std::vector<VertexHandle2> dt2_finite_vertices(const DelaunayTriangulation2& dt) {
    std::vector<VertexHandle2> out;
    for (auto it = dt.dt.finite_vertices_begin(); it != dt.dt.finite_vertices_end(); ++it)
        out.emplace_back(it);
    return out;
}
std::vector<FaceHandle2> dt2_finite_faces(const DelaunayTriangulation2& dt) {
    std::vector<FaceHandle2> out;
    for (auto it = dt.dt.finite_faces_begin(); it != dt.dt.finite_faces_end(); ++it)
        out.emplace_back(it);
    return out;
}
std::vector<EdgeHandle2> dt2_finite_edges(const DelaunayTriangulation2& dt) {
    std::vector<EdgeHandle2> out;
    for (auto it = dt.dt.finite_edges_begin(); it != dt.dt.finite_edges_end(); ++it)
        out.emplace_back(FaceHandle2(it->first), it->second);
    return out;
}
std::vector<Point2> dt2_points(const DelaunayTriangulation2& dt) {
    std::vector<Point2> out;
    for (auto it = dt.dt.points_begin(); it != dt.dt.points_end(); ++it)
        out.push_back(from_cgal(*it));
    return out;
}
std::vector<VertexHandle2> dt2_all_vertices(const DelaunayTriangulation2& dt) {
    std::vector<VertexHandle2> out;
    for (auto it = dt.dt.all_vertices_begin(); it != dt.dt.all_vertices_end(); ++it)
        out.emplace_back(it);
    return out;
}
std::vector<FaceHandle2> dt2_all_faces(const DelaunayTriangulation2& dt) {
    std::vector<FaceHandle2> out;
    for (auto it = dt.dt.all_faces_begin(); it != dt.dt.all_faces_end(); ++it)
        out.emplace_back(it);
    return out;
}
std::vector<EdgeHandle2> dt2_all_edges(const DelaunayTriangulation2& dt) {
    std::vector<EdgeHandle2> out;
    for (auto it = dt.dt.all_edges_begin(); it != dt.dt.all_edges_end(); ++it)
        out.emplace_back(FaceHandle2(it->first), it->second);
    return out;
}


// ═══════════════════════════════════════════════════════════════════════════
// CIRCULATORS
// ═══════════════════════════════════════════════════════════════════════════

std::vector<FaceHandle2> dt2_incident_faces(const DelaunayTriangulation2& dt, const VertexHandle2& v) {
    std::vector<FaceHandle2> out;
    auto c = dt.dt.incident_faces(v.vh), done = c;
    if (c != nullptr) do { out.emplace_back(c); ++c; } while (c != done);
    return out;
}
std::vector<EdgeHandle2> dt2_incident_edges(const DelaunayTriangulation2& dt, const VertexHandle2& v) {
    std::vector<EdgeHandle2> out;
    auto c = dt.dt.incident_edges(v.vh), done = c;
    if (c != nullptr) do {
        out.emplace_back(FaceHandle2(c->first), c->second); ++c;
    } while (c != done);
    return out;
}
std::vector<VertexHandle2> dt2_incident_vertices(const DelaunayTriangulation2& dt, const VertexHandle2& v) {
    std::vector<VertexHandle2> out;
    auto c = dt.dt.incident_vertices(v.vh), done = c;
    if (c != nullptr) do { out.emplace_back(c); ++c; } while (c != done);
    return out;
}
std::vector<FaceHandle2> dt2_line_walk(const DelaunayTriangulation2& dt,
                                        const Point2& p, const Point2& q) {
    std::vector<FaceHandle2> out;
    auto c = dt.dt.line_walk(to_cgal(p), to_cgal(q));
    if (c.is_empty()) return out;
    auto done = c;
    do { out.emplace_back(c); ++c; } while (c != done);
    return out;
}


// ═══════════════════════════════════════════════════════════════════════════
// CONVEX HULL
// ═══════════════════════════════════════════════════════════════════════════

std::vector<VertexHandle2> dt2_convex_hull_vertices(const DelaunayTriangulation2& dt) {
    std::vector<VertexHandle2> out;
    auto inf = dt.dt.infinite_vertex();
    auto c = dt.dt.incident_vertices(inf), done = c;
    if (c != nullptr) do {
        if (!dt.dt.is_infinite(c)) out.emplace_back(c);
        ++c;
    } while (c != done);
    return out;
}
std::vector<EdgeHandle2> dt2_convex_hull_edges(const DelaunayTriangulation2& dt) {
    std::vector<EdgeHandle2> out;
    auto inf = dt.dt.infinite_vertex();
    auto c = dt.dt.incident_edges(inf), done = c;
    if (c != nullptr) do {
        // Mirror to get the finite-face representation of the hull edge.
        auto mirror = dt.dt.mirror_edge(*c);
        out.emplace_back(FaceHandle2(mirror.first), mirror.second);
        ++c;
    } while (c != done);
    return out;
}