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
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << "\n"
#define endl "\n"

//-----
const int N = 1e6 + 7, PN = 1e7 + 7;
int pri[PN], isp[PN], low[PN], pn;
void ini() {
	fill_n(isp + 2, PN - 2, 1);
	rep(i, 2, PN) {
		if (isp[i]) { pri[pn++] = i; low[i] = i; }
		for (int j = 0; j < pn && pri[j] * i < PN; j++) {
			isp[pri[j] * i] = 0;
			low[pri[j] * i] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
int n, a[N], al[N], ar[N], far[N];
int pre[PN];
bool gao(int l, int r, int fa) {
	if (l > r) return 1;
	int rt = -1;
	for (int il = l, ir = r; il <= ir && !~rt; il++, ir--) {
		if (al[il] <= l && ar[il] >= r) rt = il;
		if (al[ir] <= l && ar[ir] >= r) rt = ir;
	}
	if (!~rt) return 0;
	else far[rt] = fa;
	return gao(l, rt - 1, rt) && gao(rt + 1, r, rt);
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ini();
	cin >> n; rep(i, 0, n) cin >> a[i];
	fill_n(pre, PN, -1); fill_n(al, n, 0);
	rep(i, 0, n) {
		for (int d = a[i]; d > 1; d /= low[d]) 
			al[i] = max(al[i], pre[low[d]] + 1);
		for (int d = a[i]; d > 1; d /= low[d])
			pre[low[d]] = i;
	}
	fill_n(pre, PN, n); fill_n(ar, n, n - 1);
	per(i, 0, n) {
		for (int d = a[i]; d > 1; d /= low[d])
			ar[i] = min(ar[i], pre[low[d]] - 1);
		for (int d = a[i]; d > 1; d /= low[d])
			pre[low[d]] = i;
	}
	if (!gao(0, n - 1, -1)) cout << "impossible";
	else rep(i, 0, n) cout << far[i] + 1 << " \n"[i == n - 1];
	return 0;
}
