// support: only +, -
// range: [-1e36, 1e36]
struct i128 {
	static const ll INF = 1e18;
	ll h, l;
	i128() {} i128(ll _h, ll _l) : h(_h), l(_l) { //h, l: [-1e18 + 1, 1e18)
		if (l >= INF || (h < 0 && l > 0)) { l -= INF; h++; }
		else if (l <= -INF || (h > 0 && l < 0)) { l += INF; h--; }
	}
	i128 operator +(const i128 b) { return i128(h + b.h, l + b.l); } //b: [-1e36, 1e36]
	i128 operator -(const i128 b) { return i128(h - b.h, l - b.l); } //b: [-1e36, 1e36]
	void out() { 
		if (h == 0) printf("%lld", l);
		else printf("%lld%018lld", h, abs(l));
	}
};

