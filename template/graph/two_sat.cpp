// time : O(m)
// space : 2 * n
// index : [0, n)
// mark[i] :
//     i-th answer
//     i => [0, n)
// !!!! : init() before use
struct TwoSat {
    static const int N = ::N << 1;
    vi G[N];
    int pre[N], dfn[N], dfs_clock;
    int scc[N], sccn;
    int mark[N], n;
    stack<int> S;
    void init(int _n) { per(i, 0, (n = _n << 1)) G[i].clear(); }
    int  new_node( ) { rep(i, 0, 2) G[n++].clear(); return n >> 1; }
    /// optionals begin
    void add_set(int a, int va) {
        a = a << 1 | va;
        G[a ^ 1].pb(a);
    }
    void add_then(int a, int va, int b, int vb) {
        a = a << 1 | va;
        b = b << 1 | vb;
        G[a].pb(b);
        G[b ^ 1].pb(a ^ 1);
    }
    void add_or (int a, int va, int b, int vb) {
        add_then(a, va ^ 1, b, vb);
    }
    void add_xor(int a, int va, int b, int vb) {
        add_then(a, va, b, vb ^ 1);
        add_then(b, vb ^ 1, a, va);
    }
    // 需要 sz(vu) 个额外的 dp 变量
    void add_at_most_one(vector<pii> vu) {
        int pre = -1;
        rep(i, 0, sz(vu)) {
            int a = vu[i].fi, va = vu[i].se;
            int dpi = new_node();
            add_then(a, va, dpi, 1);
            if (i) {
                add_then(pre, 1, dpi, 1);
                add_then(pre, 1, a, va ^ 1);
            }
            pre = dpi;
        }
    }
    /// optionals end
    void dfs(int u) {
        pre[u] = dfn[u] = ++dfs_clock;
        S.push(u);
        rep(_v, 0, sz(G[u])) {
            int v = G[u][_v];
            if (!pre[v]) {
                dfs(v);
                dfn[u] = min(dfn[u], dfn[v]);
            } else if (!scc[v])
                dfn[u] = min(dfn[u], pre[v]);
        }
        if (pre[u] == dfn[u]) {
            sccn++;
            while (1) {
                int x = S.top(); S.pop();
                scc[x] = sccn;
                if (x == u) break;
            }
        }
    }
    void find() {
        dfs_clock = sccn = 0;
        fill(pre, pre + n, 0);
        fill(scc, scc + n, 0);
        rep(i, 0, n) if (!pre[i]) dfs(i);
    }
    bool solve() {
        find();
        for (int i = 0; i < n; i += 2) {
            if (scc[i] == scc[i + 1]) return false;
            mark[i >> 1] = (scc[i] > scc[i + 1]);
        }
        return true;
    }
}   ts;
