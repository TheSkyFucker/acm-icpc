#include <bits/stdc++.h>
#define sz(x) (int)((x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b)-1; i>=(a); i--)
#define de(x) cout << #x << " => " << x << endl
using namespace std;
typedef double db;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<db, db> pdd;

#define pb push_back
typedef pair<int, int> pii;
pii operator -(const pii &a, const pii &b) { return {a.fi - b.fi, a.se - b.se}; }
pii operator +(const pii &a, const pii &b) { return {a.fi + b.fi, a.se + b.se}; }
//-----
int n, m;
pii p1, p2;
int main() {
    
    int tcase = 0; scanf("%d", &tcase);
    rep(icase, 0, tcase) {
        ///read
        cin >> n >> m;
        scanf("%d%d%d%d", &p1.fi, &p1.se, &p2.fi, &p2.se);
        ///prework
        if (p1.fi > p2.fi) swap(p1, p2);
        if (p1.se > p2.se) {
            p1.se = m - p1.se;
            p2.se = m - p2.se;
        }
        pii dp = p2 - p1;
        p2 = mp(1, 1) + dp;
        p1 = mp(n, m) - dp;
        ///work
        ll ans = 1ll * n * m;
        ans -= 1ll * p1.fi * p1.se + 1ll * (n + 1- p2.fi) * (m + 1 - p2.se);
        if (p2.fi <= p1.fi && p2.se <= p1.se) {
            ans += 1ll * (p1.fi - p2.fi + 1) * (p1.se - p2.se + 1);
        }
        ///print
        printf("%lld\n", ans);
    }
    
}
