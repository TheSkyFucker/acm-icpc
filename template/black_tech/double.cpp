
//double to interger
int sgn(int x) { return (x > 0) - (x < 0); }
int lower(int, int);
int upper(int a,int b) { 
	return sgn(a) * sgn(b) < 0 ? -lower(a * sgn(a), b * sgn(b)) : a / b + (a % b != 0); 
}
int lower(int a,int b) {
  return sgn(a) * sgn(b) < 0 ? -upper(a * sgn(a), b * sgn(b)) : a / b;
}

//get gcd
db gcd(db x, db y) {
	while (sgn(x) > 0 && sgn(y) > 0) {
		if (x > y) x -= floor(x / y) * y;
		else y -= floor(y / x) * x;
	}
	return x + y;
}
