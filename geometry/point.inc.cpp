// #include <utility>
// #include <cmath>
// #include <complex>
// #include <cassert>
typedef complex<double> point;
struct circle { point c; double r; };
struct line { point s, t; };
struct segment { point s, t; };
struct ray { point s, t; };

const double eps = 1e-6;

namespace std {
    bool operator < (point const & a, point const & b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}
double   dot(point p, point q) { return real(p) * real(q) + imag(p) * imag(q); }
double cross(point p, point q) { return real(p) * imag(q) - imag(p) * real(q); }
int ccw(point a, point b, point c) { double z = cross(b - a, c - a); return z > eps ? 1 : z < - eps ? -1 : 0; }

bool do_intersect(point a, line b) {
    return ccw(0, a - b.s, b.t - b.s) == 0;
}
bool do_intersect(line a, point b) {
    return do_intersect(b, a);
}
bool is_overwraped(line a, line b) {
    return do_intersect(a.s, b)
        and do_intersect(a.t, b);
}
bool is_parallel(line a, line b) {
    return ccw(0, a.t - a.s, b.t - b.s) == 0;
}
bool do_intersect(line a, line b) { // don't be overwrapped
    return not is_parallel(a, b)
        and not is_overwraped(a, b);
}
point intersection(line a, line b) {
    assert (do_intersect(a, b));
    double p = cross(a.t - a.s, b.t - b.s);
    double q = cross(a.t - a.s, a.t - b.s);
    return (q / p) * (b.t - b.s) + b.s;
}

template <typename T, typename U>
bool do_intersect_linelikes(T const & a, U const & b) {
    if (not do_intersect(to_line(a), to_line(b))) return false;
    point c = intersection(to_line(a), to_line(b));
    return do_intersect(a, c)
        and do_intersect(b, c);
}
template <typename T, typename U>
point intersection_linelikes(T const & a, U const & b) {
    assert (do_intersect(a, b));
    return intersection(to_line(a), to_line(b));
}

line to_line(segment a) {
    return { a.s, a.t };
}
bool do_intersect(point a, segment b) {
    return abs(cross(b.t - b.s, a - b.s)) < eps
        and dot(b.t - b.s, a - b.s) > - eps
        and dot(b.s - b.t, a - b.t) > - eps;
}
bool do_intersect(segment a, point b) {
    return do_intersect(b, a);
}
bool is_overwraped(segment a, segment b) {
    return do_intersect(a.s, b)
        and do_intersect(a.t, b);
}
bool do_intersect(segment a, segment b) {
    return do_intersect_linelikes(a, b);
}
point intersection(segment a, segment b) {
    return intersection_linelikes(a, b);
}

line to_line(ray a) {
    return { a.s, a.t };
}
bool do_intersect(point a, ray b) {
    return abs(cross(b.t - b.s, a - b.s)) < eps
        and dot(b.t - b.s, a - b.s) > - eps;
}
bool do_intersect(ray a, point b) {
    return do_intersect(b, a);
}
bool is_overwraped(ray a, ray b) {
    return (do_intersect(a.s, b) and do_intersect(a.t, b))
        or (do_intersect(b.s, a) and do_intersect(b.t, a));
}
bool do_intersect(ray a, ray b) {
    return do_intersect_linelikes(a, b);
}
point intersection(ray a, ray b) {
    return intersection_linelikes(a, b);
}






struct polygon { vector<point> ps; };
segment nth_segment(polygon const & a, int i) {
    int j = (i+1) % a.ps.size();
    return { a.ps[i], a.ps[j] };
}
bool do_intersect(ray a, segment b) { return do_intersect_linelikes(a, b); }
bool do_intersect(segment a, ray b) { return do_intersect_linelikes(a, b); }
point intersection(ray a, segment b) { return intersection_linelikes(a, b); }
point intersection(segment a, ray b) { return intersection_linelikes(a, b); }
template <typename T>
vector<point> intersections_polygon_linelike(polygon const & a, T const & b) {
    vector<point> result;
    repeat (i, a.ps.size()) {
        if (do_intersect(nth_segment(a, i), b)) {
            result.push_back(intersection(nth_segment(a, i), b));
        }
    }
    return result;
}
bool do_intersect(polygon const & a, ray const & b) {
    return not intersections_polygon_linelike(a, b).empty();
}
bool do_intersect(polygon const & a, point const & b) {
    ray c = { b, b + point(1, 0) };
    return intersections_polygon_linelike(a, c).size() % 2 == 1;
}
bool do_intersect_strict(polygon const & a, point const & b) {
    repeat (i, a.ps.size()) {
        if (do_intersect(nth_segment(a, i), b)) {
            return false; // when the point is on a segment of the polygon
        }
    }
    return do_intersect(a, b);
}
bool do_intersect_strict(polygon const & a, segment const & b) { // the boundary is not included
    vector<point> ps = intersections_polygon_linelike(a, b);
    for (point p : ps) {
        bool ignored = false;
        if (abs(p - b.s) < eps or abs(p - b.t) < eps) {
            ignored = true;
        }
        if (not ignored) {
            for (point q : a.ps) {
                if (abs(p - q) < eps) {
                    ignored = true; // when the intersection point is one of the vertex of the polygon
                    break;
                }
            }
        }
        if (not ignored) return true;
    }
    return false;
}
