//欧拉函数：小于 n && 与 n 互质的数的个数, phi(1) = 1
//欧拉降幂：求a ^ b % m (b >= phi(m))
// 1) a ^ b % m = a ^ ( b % phi(m) + phi(m) ) % m
int phi(int n) { 
	int r = n;
	for (int i = 2; i * i <= n; i++) if (n % i == 0) {
		r = r / i * (i  - 1);
		while (n % i == 0) n /= i;
	}
	if (n > 1) r = r / n * (n - 1); 
	return r;
}

﻿// gcd(a, b) = ax + by
// return gcd(a, b)
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
void min_non_negtive(ll a, ll b, ll &x, ll &y, ll n) {
    ll g = exgcd(a, b, x, y);
    if (n % gcd != 0) return -1;
    x *= n / gcd, y *= n / gcd;
    ll db = abs(b / gcd);
//  ll da = abs(a / gcd); => (x + k * db, y - k * da)
    x = ((x % db) + db) % db;
    y = (n - a * x) / b;
}
