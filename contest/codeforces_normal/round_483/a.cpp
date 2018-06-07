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
const int N = 1e2 + 7;
int n, k;
bool has[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> k;
	vi ans;
	rep(i, 0, n) {
		int ai; cin >> ai;
		if (has[ai]) continue;
		has[ai] = true;
		ans.pb(i + 1);
	}
	if (sz(ans) < k) { cout << "NO"; return 0; }
	cout << "YES" << endl;
	rep(i, 0, k) cout << ans[i] << " \n"[i == k - 1];

	return 0;
}
