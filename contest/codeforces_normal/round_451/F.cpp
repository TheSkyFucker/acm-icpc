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
const int N = 1e6 + 7;
char str[N];
int mul(int a, int b, const int &M) { return 1ll * a * b % M; }
int add(int a, int b, const int &M) { if ((a += b) >= M) a -= M; return a; }
namespace HH {
    const int N = 1e6 + 7, HN = 5;
    const int B[HN] = {10, 10, 10, 10, 10};
    const int P[HN] = {1000000007, 1000000009, 91815541, 917120411, 687840301};
    int pw[HN][N];
    void pre() {
        rep(i, 0, HN) {
            pw[i][0] = 1;
            rep(j, 1, N) pw[i][j] = mul(pw[i][j - 1], B[i], P[i]);
        }
    }
    int val(char ch) { return ch - '0'; }
    struct Hash {
        int h[HN][N], sz;
        void ini(char * s) {
            sz = strlen(s);
            rep(i, 0, HN) {
                h[i][0] = val(s[0]);
                rep(j, 1, sz) h[i][j] = add(val(s[j]), mul(h[i][j - 1], B[i], P[i]), P[i]);
            }
        }
        int geth(int l, int r, int k = 0) {
            return add(h[k][r - 1], P[k] - mul(l > 0 ? h[k][l - 1] : 0, pw[k][r - l], P[k]), P[k]);
        }
    };
}
int n;
HH::Hash hs;

bool gao(int la, int lb, int lc) {
    rep(i, 0, HH::HN)
        if (add(hs.geth(0, la, i), hs.geth(la, la + lb, i), HH::P[i]) != hs.geth(la + lb, n, i)) return false;
    char ch = str[la]; str[la] = '\0'; printf("%s+", str); str[la] = ch;
    ch = str[la + lb]; str[la + lb] = '\0'; printf("%s=", str + la); str[la + lb] = ch;
    printf("%s\n", str + la + lb);
    return true;
}

bool ok(int a, int b, int c) {
	if (a < 1 || a > c) return false;
	if (b < 1 || a > c) return false;
	if (a > 1 && str[0] == '0') return false;
	if (b > 1 && str[a] == '0') return false;
	if (c > 1 && str[a + b] == '0') return false;
	return true;
}

void solve() {
    n = strlen(str);
    HH::pre();
    hs.ini(str);
    rep(la, 1, n + 1) {
        rep(lc, la, la + 2) {
            int lb = n - la - lc; if (!ok(la, lb, lc)) continue;
            if (gao(la, lb, lc)) return;
        }
    }
    rep(lb, 1, n + 1) {
        rep(lc, lb, lb + 2) {
            int la = n - lb - lc; if (!ok(la, lb, lc)) continue;
            if (gao(la, lb, lc)) return;
        }
    }
}

int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf(" %s", str)) solve();
    return 0;
}
