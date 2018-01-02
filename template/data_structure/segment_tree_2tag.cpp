// index : [1, n]
// change : for [l, r] : val = val * tmul + tadd
struct Nd {
	db v, tadd, tmul; int sz;
	Nd() {} Nd(db v, db tmul, db tadd) : v(v), tmul(tmul), tadd(tadd) {}
	void chg(db _tmul, db _tadd) {
		tmul = tmul * _tmul;
		tadd = tadd * _tmul + _tadd;
		v = v * _tmul + _tadd * sz;
	}
	void upd(const Nd &ls, const Nd &rs) { v = ls.v + rs.v; }
};
struct Tree {
	static const int N = ::N << 2;
	Nd nd[N];
#define ls ((o) << 1)
#define rs ((o) << 1 | 1)
	void upd(int o) { nd[o].upd(nd[ls], nd[rs]); }
	void dwn(int o) {
		nd[ls].chg(nd[o].tmul, nd[o].tadd);
		nd[rs].chg(nd[o].tmul, nd[o].tadd);
		nd[o].tmul = 1.0; nd[o].tadd = 0.;
	}
	void bud(int o, int l, int r) {
		nd[o] = Nd(0., 1., 0.);
		nd[o].sz = r - l + 1;
		if (l == r) { nd[o].v = a[l]; return; }	 //a[] : init array
		int mid = l + r >> 1;
		bud(ls, l, mid);
		bud(rs, mid + 1, r);
		upd(o);
	}
	void chg(int o, int l, int r, int ql, int qr, db tmul, db tadd) {
		if (ql <= l && qr >= r) { nd[o].chg(tmul, tadd); return; }
		dwn(o);
		int mid = l + r >> 1;
		if (ql <= mid) chg(ls, l, mid, ql, qr, tmul, tadd);
		if (qr >  mid) chg(rs, mid + 1, r, ql, qr, tmul, tadd);
		upd(o);
	}
	db qry(int o, int l, int r, int ql, int qr) {
		if (ql <= l && qr >= r) return nd[o].v;
		dwn(o);
		int mid = l + r >> 1;
		db ret = 0;
		if (ql <= mid) ret += qry(ls, l, mid, ql, qr);
		if (qr >  mid) ret += qry(rs, mid + 1, r, ql, qr);
		return ret;
	}
}	tree;
