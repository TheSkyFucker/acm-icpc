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
const int N = 2e5 + 7;
const ll INF = 10000000000000000ll;
int n;
struct Big {
    ll a, b;
    Big() {} Big(ll a, ll b) : a(a), b(b) {}
    void operator +=(const ll &d) {
        b += d;
        if (b >= INF) { b -= INF, a++; }
        if (b < 0) { b += INF, a--; }
    }
    void out() {
        if (a > 0 && b < 0) {
            b += INF, a--;
        }
        if (a < 0 && b > 0) {
            b -= INF, a++;
        }
        if (a == 0) printf("%lld\n", b);
        else printf("%lld%016lld\n", a, abs(b));
    }
};
void solve() {
    map<int, int> M;
    Big ans(0, 0);
    rep(i, 1, n + 1) {
        int a; scanf("%d", &a);
        ans += (2ll * i - n - 1) * a;
        if (M.count(a - 1)) ans += -M[a - 1];
        if (M.count(a + 1)) ans += M[a + 1];
        M[a]++;
    }
    ans.out();
}
int main() {
    while (~scanf("%d", &n)) solve();
    return 0;
}

