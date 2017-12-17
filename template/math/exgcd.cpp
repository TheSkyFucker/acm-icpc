// gcd(a, b) = ax + by
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
