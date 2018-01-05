//index : [0, n)
//time : O(m + n)
int bel[N]; // which scc i-th node belong
struct Tarjan {
    static const int N = 1e5 + 7;
    int dfn[N], low[N], tim;
    int stk[N], top;
    vector<vi> scc, ng; //ng : new graph
    void dfs(int u, vi g[]) {
        low[stk[top++] = u] = dfn[u] = tim++;
        for (auto v : g[u])
            if (!~dfn[v])
                dfs(v, g), low[u] = min(low[u], low[v]);
            else if (!~bel[v])
                low[u] = min(low[u], dfn[v]);
        if (low[u] == dfn[u]) {
            scc.pb(vi());
            do {
                scc.back().pb(stk[--top]);
                bel[stk[top]] = sz(scc);
            }   while (stk[top] != u);
        }
    }
    void solve(int n, vi g[]) {
        scc.clear(); ng.clear();
        fill_n(dfn, n, -1); tim = 0;
        fill_n(bel, n, -1); top = 0;
        rep(i, 0, n) if (!~dfn[i]) dfs(i, g);
        rep(i, 0, n) bel[i]--;
        ng.resize(sz(scc));
        rep(i, 0, n) for (auto j : g[i]) if (bel[i] != bel[j]) 
			ng[bel[i]].pb(bel[j]);
    }
}   tar;

