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

int mul(int a, int b, const int &M) { return 1ll * a * b % M; }
int add(int a, int b, const int &M) { if ((a += b) >= M) a -= M; return a; }
namespace HH {
    const int N = 1e5 + 7, HN = 2;
    const int B[3] = {29123, 16381, 92083};
    const int P[3] = {1000000007, 1000000009, 91815541};
    int pw[HN][N];
    void pre() {
        rep(i, 0, HN) {
            pw[i][0] = 1;
            rep(j, 1, N) pw[i][j] = mul(pw[i][j - 1], B[i], P[i]);
        }
    }
    int val(char ch) { return ch; }
    struct Hash {
        int h[HN][N], sz;
        void ini(string s) {
            sz = sz(s);
            rep(i, 0, HN) {
                h[i][0] = val(s[0]);
                rep(j, 1, sz) h[i][j] = add(val(s[j]), mul(h[i][j - 1], B[i], P[i]), P[i]);
            }
        }
        int geth(int l, int r, int k = 0) {
            return add(h[k][r - 1], P[k] - mul(l > 0 ? h[k][l - 1] : 0, pw[k][r - l], P[k]), P[k]);
        }
        int swap(int l, int r, int k = 0) {
            if (l > r) swap(l, r);
            int ret = geth(r + 1, sz, k);
            ret = add(ret, mul(geth(0, l, k), pw[k][sz - l], P[k]), P[k]);
            ret = add(ret, mul(geth(l + 1, r, k), pw[k][sz - r], P[k]), P[k]);
            ret = add(ret, mul(geth(l, l + 1, k), pw[k][sz - r - 1], P[k]), P[k]);
            ret = add(ret, mul(geth(r, r + 1, k), pw[k][sz - l - 1], P[k]), P[k]);
            return ret;
        }
    };
}

const int N = 5e3 + 7;
string s[N];
int n, k;
void solve() {
    rep(i, 0, k) cin >> s[i];
    map<pii, int> M;
    rep(i, 0, k){
        //de(i);
        HH::Hash h; h.ini(s[i]);
        set<pii> S;
        rep(a, 0, n) rep(b, a + 1, n) {
            pii hv = {h.swap(a, b, 0), h.swap(a, b, 1)};
           // dd(a); dd(b); dd(hv.fi); de(hv.se);
            if (S.find(hv) != S.end()) continue;
            else S.insert(hv);
            if (++M[hv] == k) {
                swap(s[i][a], s[i][b]);
                cout << s[i] << endl;
                return;
            }
        }
    }
    puts("-1");
}


int main() {
    //freopen("xx.in", "r", stdin);
    HH::pre();
    while (~scanf("%d%d", &k, &n)) solve();
    return 0;
}