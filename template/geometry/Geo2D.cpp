typedef db T;
T eps = 1e-10;
int sgn(T d) { return (d > eps) - (d < -eps); }
struct P {
	T x, y;
	P() {}
	P(T x, T y): x(x), y(y) {}
	T operator *(const P &b) const { return x * b.x + y * b.y; }
	T operator /(const P &b) const { return x * b.y - y * b.x; }
	P operator +(const P &b) const { return P(x + b.x, y + b.y); }
	P operator -(const P &b) const { return P(x - b.x, y - b.x); }
	P operator *(const T &d) const { return P(x * d, y * d); }
	P operator /(const T &d) const { return P(x / d, y / d); }
	T abs() const { return sqrt(x * x + y * y); }
	T norm() const { return x * x + y * y; }
	P rot90() const { return P(-y, x); }
	void show() { dd(x); de(y); }
	void read() { scanf("%lf%lf", &x, &y); }
};

