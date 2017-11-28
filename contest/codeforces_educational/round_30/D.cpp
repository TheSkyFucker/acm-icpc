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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
const int N = 1e5 + 7;
int n, k, _;
int ans[N];
void gao(int l, int r) {
	if (l + 1 < r && k) {
		int mid = l + r >> 1; k -= 2;
		gao(l, mid);
		gao(mid, r);
	}
	else per(i, l, r) ans[i] = _--;
}
		
void solve() {
	if (!(k & 1)) { puts("-1"); return; } else k--;
	_ = n; gao(1, n + 1);
	if (k > 0) { puts("-1"); return; }
	rep(i, 1, n + 1) printf("%d%c", ans[i], " \n"[i == n]);
}

int main() {
	while (~scanf("%d%d", &n, &k)) solve();
	return 0;
}
