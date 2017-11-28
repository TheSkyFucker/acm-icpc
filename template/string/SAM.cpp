struct SAM {
	static const int N = ::N << 1;
	int la, m, f[N], mxl[N], nxt[N][26];
	void ini() { la = m = 1; }
	void add(int ch) {
		int p, x; mxl[++m] = mxl[la] + 1;
		for (x = la; x && !nxt[x][ch]; x = f[x]) nxt[x][ch] = m;
		p = nxt[x][ch], la = m;
		if (!x) { f[m] = 1; return; }
		if (mxl[p] == mxl[x] + 1){ f[m] = p; return ;}
		mxl[++m] = mxl[x] + 1, f[m] = f[p], f[p] = f[m - 1] = m;
		rep(i, 0, 26) nxt[m][i] = nxt[p][i];
		for(; x && nxt[x][ch] == p; x = f[x]) nxt[x][ch] = m;
	}
}	sam;
