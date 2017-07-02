typedef complex<double> point;
struct circle { point p; double r; };
struct line { point s, t; };
struct segment { point s, t; };
struct ray { point s, t; };

/**
 * @note あまり小さくすると誤差で死ぬ
 */
const double eps = 1e-6;
double sq(double x) { return pow(x, 2); }

struct point { double y, x; };
point operator + (point a, point b) { return (point) { a.y + b.y, a.x + b.x }; }
point operator - (point a, point b) { return (point) { a.y - b.y, a.x - b.x }; }
point operator * (point a, double b) { return (point) { a.y * b, a.x * b }; }
point operator / (point a, double b) { return (point) { a.y / b, a.x / b }; }
point operator < (point a, point b) { return make_pair(a.y, a.x) < make_pair(b.y, b.x); }
double distance(point a, point b) { return sqrt(sq(a.y - b.y) + sq(a.x - b.x)); }
double   dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
int ccw(point a, point b, point c) { double z = cross(b - a, c - a); return z > eps ? 1 : z < - eps ? -1 : 0; }




/**
 * @brief segment - segment, inclusive
 */
bool does_intersect(segment const & a, segment const & b){
    return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 and
           ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;
}

/**
 * @brief point and line
 */
bool does_intersect(point a, line b) { return ccw(0, a - b.s, b.t - b.s) == 0; }
bool does_intersect(line a, point b) { return does_intersect(b, a); }

/**
 * @brief line and line
 */
bool is_parallel(line a, line b) { return ccw(0, a.t - a.s, b.t - b.s) == 0; }
bool is_same(line a, line b) { return does_intersect(a.s, b) and does_intersect(a.t, b); }
/**
 * @note false if two lines are the same
 */
bool does_intersect(line a, line b) {
    return not is_parallel(a, b)
        and not is_same(a, b);
}
point intersection(line a, line b) {
    assert (does_intersect(a, b));
    double p = cross(a.t - a.s, b.t - b.s);
    double q = cross(a.t - a.s, a.t - b.s);
    return (q / p) * (b.t - b.s) + b.s;
}


/**
 * @note helper for segments and rays
 */
template <typename T, typename U>
bool does_intersect_linelikes(T const & a, U const & b) {
    if (not does_intersect(to_line(a), to_line(b))) return false;
    point c = intersection(to_line(a), to_line(b));
    return does_intersect(c, a)
        and does_intersect(c, b);
}


line to_line(segment a) {
    return { a.s, a.t };
}
bool does_intersect(point a, segment b) {
    return abs(cross(b.t - b.s, a - b.s)) < eps
        and dot(b.t - b.s, a - b.s) > - eps
        and dot(b.s - b.t, a - b.t) > - eps;
}
bool does_intersect(segment a, point b) {
    return does_intersect(b, a);
}
bool is_overwraped(segment a, segment b) {
    return does_intersect(a.s, b)
        and does_intersect(a.t, b);
}
bool does_intersect(segment a, segment b) {
    return does_intersect_linelikes(a, b);
}
point intersection(segment a, segment b) {
    assert (does_intersect(a, b));
    return intersection(to_line(a), to_line(b));
}


line to_line(ray a) {
    return { a.s, a.t };
}
bool does_intersect(point a, ray b) {
    return abs(cross(b.t - b.s, a - b.s)) < eps
        and dot(b.t - b.s, a - b.s) > - eps;
}
bool does_intersect(ray a, point b) {
    return does_intersect(b, a);
}
bool is_overwraped(ray a, ray b) {
    return (does_intersect(a.s, b) and does_intersect(a.t, b))
        or (does_intersect(b.s, a) and does_intersect(b.t, a));
}
bool does_intersect(ray a, ray b) {
    return does_intersect_linelikes(a, b);
}
point intersection(ray a, ray b) {
    assert (does_intersect(a, b));
    return intersection(to_line(a), to_line(b));
}






struct polygon { vector<point> ps; };
segment nth_segment(polygon const & a, int i) {
    int j = (i+1) % a.ps.size();
    return { a.ps[i], a.ps[j] };
}
bool does_intersect(ray a, segment b) { return does_intersect_linelikes(a, b); }
bool does_intersect(segment a, ray b) { return does_intersect_linelikes(a, b); }
point intersection(ray a, segment b) { return intersection_linelikes(a, b); }
point intersection(segment a, ray b) { return intersection_linelikes(a, b); }
template <typename T>
vector<point> intersections_polygon_linelike(polygon const & a, T const & b) {
    vector<point> result;
    repeat (i, a.ps.size()) {
        if (does_intersect(nth_segment(a, i), b)) {
            result.push_back(intersection(nth_segment(a, i), b));
        }
    }
    return result;
}
bool does_intersect(polygon const & a, ray const & b) {
    return not intersections_polygon_linelike(a, b).empty();
}
bool does_intersect(polygon const & a, point const & b) {
    ray c = { b, b + point(1, 0) };
    return intersections_polygon_linelike(a, c).size() % 2 == 1;
}
bool does_intersect_strict(polygon const & a, point const & b) {
    repeat (i, a.ps.size()) {
        if (does_intersect(nth_segment(a, i), b)) {
            return false; // when the point is on a segment of the polygon
        }
    }
    return does_intersect(a, b);
}
bool does_intersect_strict(polygon const & a, segment const & b) { // the boundary is not included
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
