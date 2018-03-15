struct C {
	P o; T r;
	C() {}
	C(P o, T r): o(o), r(r) {}
};

// point (inside / on / outside) circle
bool operator < (const P& p, const C& c) { return sgn((p - c.o).abs() - c.r) <  0; }
bool operator <=(const P& p, const C& c) { return sgn((p - c.o).abs() - c.r) <= 0; }
bool operator ==(const P& p, const C& c) { return sgn((p - c.o).abs() - c.r) == 0; }

// !!!! : if a.o = b.o then return nothing even if a.r = b.r;
// time : O(1)
vector<P> insCC(C a, C b) {
    vector<P> res;
    T x = (a.o - b.o).norm();
    if (sgn(x) == 0) return res;
    T y = ((a.r * a.r - b.r * b.r) / x + 1) / 2,
      d = a.r * a.r / x - y * y;
    if (sgn(d) < 0) return res;
    d = max(d, 0.);
    P mid = (b.o - a.o) * y + a.o,
      del = ((b.o - a.o) * sqrt(d)).rot90();
    return {mid - del, mid + del};
}

// description : return a point inside all Circle, if exist;
// time : O(sz(vc) ^ 2 + sz(vc) ^ 3)
vector<P> insCCC(vector<C> vc) {
    // type 1 : intersection is a circle
    for (auto ci : vc) {
        bool ok = true;
        for (auto cj : vc) if (!(ci.o <= cj)) {
            ok = false;
            break;
        }
        if (ok) return {ci.o};
    }
    // type 2 : board point of intersection should be a point : circle a & b
    for (auto ci : vc) for (auto cj : vc) {
        auto vp = insCC(ci, cj);
        for (auto p : vp) {
            bool ok = true;
            for (auto ck : vc) if (!(p <= ck)) {
                ok = false;
                break;
            }
            if (ok) return {p};
        }
    }
    return {};
}
