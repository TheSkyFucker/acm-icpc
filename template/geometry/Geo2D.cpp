typedef db T;
T eps = 1e-10;
int sgn(T d) { return (d > eps) - (d < -eps); }
struct P {
	T x, y;
	P(){}P(T x, T y): x(x), y(y) {}
	void read() { scanf("%lf%lf", &x, &y); }
	void out() { dd(x); de(y); }
	T operator *(const P &b) const { return x * b.x + y * b.y; }
	T operator /(const P &b) const { return x * b.y - y * b.x; }
	P operator +(const P &b) const { return P(x + b.x, y + b.y); }
	P operator -(const P &b) const { return P(x - b.x, y - b.x); }
	P operator *(const T &d) const { return P(x * d, y * d); }
	P operator /(const T &d) const { return P(x / d, y / d); }
	T abs() const { return sqrt(x * x + y * y); }
	T norm() const { return x * x + y * y; }
	// (abs(), 0) 逆时针 rot ang() => (x, y)
	T ang() const { return atan2(y, x); } //[-pi, pi]
	//逆时针 rot pi/2
	P rot90() const { return P(-y, x); }
	//逆时针 rot a
	P rot(const T &a) const { return P(cos(a) * x - sin(a) * y, sin(a) * x + cos(a) * y); } 
};

bool onPS(P p, P s, P t) { return sgn((t - s) / (p - s)) == 0 && sgn((p - s) * (p - t)) <= 0; }
