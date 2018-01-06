db gcd(db x, db y) {
	while (sgn(x) > 0 && sgn(y) > 0) {
		if (x > y) x -= floor(x / y) * y;
		else y -= floor(y / x) * x;
	}
	return x + y;
}
