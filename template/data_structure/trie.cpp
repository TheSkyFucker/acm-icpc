// 'a' .. 'z'
// !!!! : ini() 
struct Trie {
	static const int N = ::N;
	int son[N][26], _;
	int ne() { fill_n(son[_], 26, -1); return _++; }
	void ini() { _ = 0; ne(); }
	void insert(const string &s) {
		int u = 0;
		for (auto ch : s) {
			int &v = son[u][ch - 'a'];
			if (!~v) v = ne();
			u = v;
		}
	}
}	tree;
