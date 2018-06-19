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
const int N = 1e6 + 7;
int cnt[N], n;
void solve() {
	fill_n(cnt, N, 0);
	cin >> n;
	rep(i, 0, n) {
		int ai; cin >> ai;
		for (int j = 2; j * j <= ai; j++) {
			if (ai % j == 0) {
				cnt[j]++;
				while (ai % j == 0) ai /= j;
			}
		}
		if (ai > 1) cnt[ai]++;
	}
	int ans = 0;
	rep(i, 0, N) {
		ans += (cnt[i] + 2) / 3;
	}
	cout << ans << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tcas; cin >> tcas;
	rep(cas, 0, tcas) {
		solve();
	}
	return 0;
}
