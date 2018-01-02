// index : [0, n)
// !!!! : init(n) before use
struct Edge { int to, cap; Edge() {} Edge(int to, int cap) : to(to), cap(cap) {} };
struct Dinic{
    static const int N = 2e4 + 7, M = 2e5 + 7, INF = 1e9 + 7;
    int n, dis[N], que[N], hed[N], fst[N], m, nxt[M];
    Edge E[M];
    void ini(int _n) { fill_n(hed, n = _n, -1); m = 0; }
    void addedge(int s, Edge e) { nxt[m] = hed[s]; hed[s] = m; E[m++] = e; }
    bool bfs(int S, int T) {
    	fill_n(dis, n, -1); dis[que[0] = S] = 0;
        for (int h = 0, t = 1; h < t; ) {
            int u = que[h++];
            for (int i = hed[u]; ~i; i = nxt[i]) {
                Edge &e = E[i]; if (!e.cap || ~dis[e.to]) continue;
                dis[e.to] = dis[u] + 1;
                que[t++] = e.to;
                if (e.to == T) return true;
            }
        }
        return false;
    }
    int dfs(int u, const int &T, int mx) {
        if (u == T) return mx;
        int r = mx;
        for (int &i = fst[u]; ~i; i = nxt[i]) {
            Edge &e = E[i]; if (!e.cap || dis[e.to] <= dis[u]) continue;
            int f = dfs(e.to, T, min(r, e.cap));
            if (f) {
                e.cap -= f;  
                E[i ^ 1].cap += f;
                if (!(r -= f)) return mx;
            }
        }
        if (r == mx) dis[u] = -1;
        return mx - r;
    }
    int work(int S, int T) {
        int ret = 0;
        while (bfs(S, T)) {
        	rep(i, 0, n) fst[i] = hed[i];
            ret += dfs(S, T, INF);
        }
        return ret;
    }
}    din;
