//time : n * m
//space : 2 * n
//index : [0, 2n)
//bool[i] : 
//    i => [0, n)
//    (i << 1 | 0) == 1 => bool[i] = 1
//    (i << 1 | 1) == 1 => bool[i] = -1
struct TwoSat {
    static const int N = 1e5 + 7;
    int ans[N], col[N], tot, n; vi G[N];
    void init(int _n) { per(i, 0, (n = _n)) G[i].clear(); }
    bool dfs(int u) {
        if (col[u] == -1) return false;
        if (col[u] ==  1) return true;
        ans[tot++] = u;
        col[u] = 1;
        col[u ^ 1] = -1;
        rep(_v, 0, sz(G[u])) if (!dfs(G[u][_v])) return false;
        return true;
    }
    bool solve() {
        rep(i, 0, n) if (!col[i]) {
            tot = 0;
            if (!dfs(i)) {
                rep(j, 0, tot) col[ans[j]] = col[ans[j] ^ 1] = 0;
                if (!dfs(i ^ 1)) return false;
            }
        }
        return true;
    }
}   ts;
