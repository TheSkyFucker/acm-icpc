//HN: hash level
//N: max string lenth
//do HH::pre() before use 
int mul(int a, int b, const int &M) { return 1ll * a * b % M; }
int add(int a, int b, const int &M) { if ((a += b) >= M) a -= M; return a; }
namespace HH {
    const int N = 1e5 + 7, HN = 2;
    const int B[5] = {29123, 38734667, 16381, 21788233, 92083};
    const int P[5] = {1000000007, 1000000009, 91815541, 687840301, 917120411};
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
        void ini(string s) { //void ini(char * s) {
            sz = sz(s);      //    sz = strlen(s);
            rep(i, 0, HN) {
                h[i][0] = val(s[0]);
                rep(j, 1, sz) h[i][j] = add(val(s[j]), mul(h[i][j - 1], B[i], P[i]), P[i]);
            }
        }
        int geth(int l, int r, int k = 0) {	//[l, r)
            return add(r > 0 ? h[k][r - 1] : 0, P[k] - mul(l > 0 ? h[k][l - 1] : 0, pw[k][r - l], P[k]), P[k]);
        }
        int swap(int l, int r, int k = 0) { //[l, r)
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
