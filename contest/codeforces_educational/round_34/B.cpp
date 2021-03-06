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
const int INF = 1e9 + 7;
int h1, a1, c, h2, a2, ned;
bool ok(int ans) {
    return 1ll * (ans - ned) * c + h1 > 1ll * a2 * (ans - 1);
}
void solve() {
    ned = (h2 - 1) / a1 + 1;
    int ans = -1;
    for (int l = ned, r = INF, mid = l + r >> 1; l <= r; mid = l + r >> 1)
        ok(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    printf("%d\n", ans);
    rep(i, 0, ans - ned) puts("HEAL");
    rep(i, 0, ned) puts("STRIKE");
}
int main() {
    while (~scanf("%d%d%d%d%d", &h1, &a1, &c, &h2, &a2)) solve();
}
