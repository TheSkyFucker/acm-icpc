// desc : bud a cartesion tree from a[0] .. a[n - 1]
// time : O(N)
// !!!! : return root of the tree
int ls[N], rs[N], root;
int cartesion_tree(int a[], int n) {
	vi stk;
	fill_n(ls, n, -1);
	fill_n(rs, n, -1);
	rep(i, 0, n) {
		int pre = -1;
		while (!stk.empty() && a[stk.back()] < a[i]) {
			pre = stk.back(); stk.pop_back();
		}
		ls[i] = pre;
		if (!stk.empty()) rs[stk.back()] = i;
		stk.pb(i);
	}
	return stk[0];
}
