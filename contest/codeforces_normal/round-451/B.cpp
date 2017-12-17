#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

// gcd(a, b) = ax + by
// return gcd(a, b)
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
bool min_non_negtive(ll a, ll b, ll &x, ll &y, ll n) {
    ll g = exgcd(a, b, x, y);
    if (n % g != 0) return false;
    x *= n / g, y *= n / g;
    ll db = abs(b / g);
//  ll da = abs(a / gcd); => (x + k * db, y - k * da)
    x = ((x % db) + db) % db;
    y = (n - a * x) / b;
    return true;
}

ll n, a, b;
void solve() {
    ll x, y;
    if (!min_non_negtive(a, b, x, y, n) || y < 0) {
        puts("NO");
        return;
    }
    printf("YES\n%lld %lld\n", x, y);
}

int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf("%lld%lld%lld", &n, &a, &b))solve();
    return 0;
}

