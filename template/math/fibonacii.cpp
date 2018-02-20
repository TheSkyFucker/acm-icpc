// f[i] : i-th fibonacii begin with 1, 1
// f[i] = sqrt(5) / 5 * (((1 + sqrt(5)) / 2) ^ n - ((1 - sqrt(5)) / 2) ^ n)

// F(a, b, i) : ................... a, b
// F(a, b, i) = f(i - 1) * b + f(i - 2) * a
int F(int a, int b, int x) {
	if (x == 1) return a;
	if (x == 2) return b;
	return add(mul(f[x - 1], b), mul(f[x - 2], a));
}
// S(a, b, x) : sum of F(a, b, 1) ... F(a, b, x)
// S(a, b, x) = F(a, b, x + 2) - b
int S(int a, int b, int x) { return add(F(a, b, x + 2), MOD - b); }
