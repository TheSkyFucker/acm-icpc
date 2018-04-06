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
const int N = 1e5 + 7;
int n, k, m, cost[N];
string word[N];
map<string, int> Map;
int main() {
	scanf("%d%d%d", &n, &k, &m);
	rep(i, 0, n) {
		cin >> word[i];
		Map[word[i]] = i;
	}
	rep(i, 0, n) scanf("%d", cost + i);
	rep(i, 0, k) {
		int l; scanf("%d", &l);
		vi v; v.resize(l);
		rep(j, 0, l) scanf("%d", &v[j]), v[j]--;
		int mi = INT_MAX;
		rep(j, 0, l) mi = min(cost[v[j]], mi);
		rep(j, 0, l) cost[v[j]] = mi;
	}
	ll ans = 0;
    rep(i, 0, m) {
		string msg; cin >> msg;
		ans += cost[Map[msg]];
	//	de(cost[Map[msg]]);
	}
	cout << ans;
	return 0;
}
