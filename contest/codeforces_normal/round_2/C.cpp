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

//-----
const db eps = 1e-7;
db Sqr(db d) { return d * d; }
bool ls(const db &a, const db &b) { return a + eps < b; }
bool eq(const db &a, const db &b) { return fabs(a - b) < eps; }
//-----
pair<pdd, db> p[3];
pdd operator +(const pdd &a, const pdd &b) { return {a.fi + b.fi, a.se + b.se}; }
pdd operator -(const pdd &a, const pdd &b) { return {a.fi - b.fi, a.se - b.se}; }
pdd operator *(const pdd &a, const db &b) { return {a.fi * b, a.se * b}; }
db len(const pdd &a) { return sqrt(Sqr(a.fi) + Sqr(a.se)); }
//-----
db F(pdd cur) {
    db ret = 0.0;
    db t[3];
    rep(i, 0, 3) t[i] = len(cur - p[i].fi) / p[i].se;
    rep(i, 0, 3) ret += Sqr(t[i] - t[(i + 1) % 3]);
    return ret;
}
int main() {
    
    ///read
    rep(i, 0, 3) scanf("%lf%lf%lf", &p[i].fi.fi, &p[i].fi.se, &p[i].se);
    
    ///work
    pdd cur = {0, 0};
    rep(i, 0, 3) cur = cur + p[i].fi; cur = cur * (1.0 / 3.0);
    for (db len = 1.0; ls(0, len); ) {
        static pdd dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool work = false;
        rep(d, 0 ,4) {
            pdd nex = cur + dir[d] * len;
            if (F(nex) + eps * eps < F(cur)) {
                cur = nex;
                work= true;
                break;
            }
        }
        if (!work) len = len * 0.7;
    }
    
    ///print
    if (F(cur) < 1e-5) printf("%.5f %.5f", cur.fi, cur.se);
    return 0;
    
    
}

