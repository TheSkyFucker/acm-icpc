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
const int N = 2e5 + 6;
const int INF = 1e9 + 7;
int n, a[N], b[N], c[N];
vi v;
void solve(){
    rep(i, 0, n) {
        scanf("%d", &a[i]);
        int p = lower_bound(all(v), a[i]) - v.begin();
        b[i] = min(max(0, a[i] - (p - 1) * (p - 1)), p * p - a[i]);
        c[i] = a[i] != p * p ? 0 : 1 + !a[i];
    }
    sort(b, b + n);
    sort(c, c + n);
    int cnt = 0; rep(i, 0, n) cnt += !b[i];
    ll ans = 0;
    if (cnt <= n / 2) rep(i, 0, n / 2) ans += b[i];
    else rep(i, 0, n / 2) ans += c[i];
    printf("%lld\n", ans);
}

int main() {
    //freopen("xx.in", "r", stdin);
    for (int i = 0; i * i <= INF; i++) v.pb(i*i);
    while (~scanf("%d", &n)) solve();
    return 0;
}
