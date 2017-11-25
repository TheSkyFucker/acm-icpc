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
const int INF = 1e9 + 7;
int n, k, a[N];
int pre[N], suf[N];
int solve() {
	int mx = -INF; rep(i, 1, n + 1) scanf("%d", &a[i]), mx = max(mx, a[i]);
	if (k >= 3) return mx;
	pre[0] = INF; rep(i, 1, n + 1) pre[i] = min(pre[i - 1], a[i]);
	suf[n + 1] = INF; per(i, 1, n + 1) suf[i] = min(suf[i + 1], a[i]);
	if (k == 1) return pre[n];
	//rep(i, 1, n + 1) de(a[i]);
	int ret = -INF;
	rep(i, 1, n + 1) ret = max(ret, pre[i]);
	rep(i, 1, n + 1) ret = max(ret, suf[i]);
	return ret;
}
	
int main() {
	while (~scanf("%d%d", &n, &k)) printf("%d\n", solve());
	return 0;
}
