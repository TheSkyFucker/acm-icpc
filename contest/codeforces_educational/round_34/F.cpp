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
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int tab[N][N], n;
pii op[5];
int dp[4][N][1 << 12];

void solve() {
    rep(i, 1, 4 + 1) scanf("%d", &op[i].se);
    rep(i, 0, 4) rep(j, 0, n) {
        char ch; scanf(" %c", &ch);
        tab[i][j] = ch == '*';
    }
    //rep(i, 0, 4) rep(j, 0, n) printf("%d%c", tab[i][j], " \n"[j == n - 1]);
    int lim = 1 << 12;
    rep(j, 0, n + 1) rep(i, 0, 4) fill_n(dp[i][j], lim, INF);
    dp[0][0][tab[0][0] << 11] = 0;
    dp[0][0][0] = tab[0][0] * op[1].se;
    tab[0][n] = 0;
    rep(j, 0, n) {
        rep(i, 0, 4) {
            int ni = (i + 1) % 4;
            int nj = j + (i == 3);
            rep(mask, 0, lim) {
                if (dp[i][j][mask] == INF) continue;
                if (i == 3 && nj >= 3) {
                    dp[3][nj][0] = min(dp[3][nj][0], dp[i][j][mask] + op[4].se);
                }
                if (mask & 1) continue;
                int nxt = mask >> 1 | (tab[ni][nj] << 11);
                rep(k, 0, min(ni + 1, nj + 1) + 1) {
                    int nmask = nxt & op[k].fi;
        //            dd(ni); dd(nj); de(nmask);
                    if (ni == 3 && nj == 4 && nmask == 0) {
                    //    de(mask);
                    //    dd(k); de(dp[i][j][mask]);
                    //    de(dp[i][j][mask] + op[k].se);
                    }
                    dp[ni][nj][nmask] = min(dp[ni][nj][nmask], dp[i][j][mask] + op[k].se);
                }

                //dd(i); dd(j); dd(mask); de(dp[i][j][mask]);
            }
        }
    }
    printf("%d\n", dp[0][n][0]);
}

int main() {
    rep(i, 0, 4) {
        int base = (1 << 4) - (1 << (4 - i));
        rep(j, 0, i + 1) op[i].fi |= base << ((3 - j) * 4);
        op[i].fi = (1 << 12) - 1 - op[i].fi;
        //rep(j, 0, 12) printf("%d", op[i].fi >> j & 1); puts("");
    }
    while (~scanf("%d", &n)) solve();
    return 0;
}