// index : [0, n)
// limit: 2^M >= N
// !!! : bud()
namespace RMQ {
    const int N = ::N, M = 22;
    int lg2[N];
    int st[N][M];
    void bud(int n, int a[]) {
        assert((1 << M) > n);
        lg2[0] = -1; rep(i, 1, n + 1) lg2[i] = lg2[i >> 1] + 1;
        rep(i, 0, n) st[i][0] = a[i];
        rep(j, 1, M) rep(i, 0, n) {
            if (i + (1 << j) > n) break;
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int qry(int l, int r) {
        if (l > r) swap(l, r);
        int lv = lg2[r - l + 1];
        return max(st[l][lv], st[r - (1 << lv) + 1][lv]);
    }
}