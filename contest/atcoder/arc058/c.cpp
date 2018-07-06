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
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
 
//-----
int n, m;
bool ban[10];
vi v;
int dfs(int cur) {
	if (cur >= n) return cur;
	int ret = INT_MAX;
	for (auto e : v) if (cur * 10 + e) {
		ret = min(ret, dfs(cur * 10 + e));
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 0, m) {
		int ai; cin >> ai;
		ban[ai] = true;
	}
	rep(i, 0, 10) if (!ban[i]) v.pb(i);
	cout<<dfs(0);
	return 0;
}
