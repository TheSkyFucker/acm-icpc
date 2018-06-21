typedef vector<P> polygon;

// time : O(sz(P));
T area(polygon p) {
	T ret = 0;
	p.pb(p[0]);
	rep(i, 0, sz(p) - 1) ret += p[i] / p[i + 1];
	return fabs(ret) / 2.;
}

// !!!! : pay attention if the area is zero
// time : O(sz(P));
P gravity(polygon p) {
  P o = p[0], g(0, 0);
  rep(i, 0, sz(p)) p[i] = p[i] - o;
  p.pb(p[0]);
  T area = 0;
  rep(i, 0, sz(p) - 1) {
    T tmp = p[i] / p[i + 1];
    g = g + (p[i] + p[i + 1]) * tmp;
    area += tmp;
  }
  return g / (3. * area) + o;
}

// point in polygon
int inPpolygon(P p, polygon A) { // -1 : on , 0 : out , 1 : in
  int res = 0;
  rep(i, 0, sz(A)) {
    P u = A[i], v = A[(i + 1) % sz(A)];
      if (onPS(p, u, v)) return -1;
      T cross = sgn((v - u) / (p - u)), d1 = sgn(u.y - p.y), d2 = sgn(v.y - p.y);
      if (cross > 0 && d1 <= 0 && d2 > 0) ++ res;
      if (cross < 0 && d2 <= 0 && d1 > 0) -- res;
  }
  return res;
}
