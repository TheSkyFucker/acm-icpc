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
const int N = 2e5 + 7;
int a[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int nn; cin >> nn;
	map<int, pii> Map;
	rep(i, 0, nn) {
		int ni; cin >> ni;
		int sum = 0;
		rep(j, 0, ni) cin >> a[j], sum += a[j];
		rep(j, 0, ni) {
			if (Map.count(sum - a[j]) && Map[sum - a[j]].fi != i) {
				auto e = Map[sum - a[j]];
				cout << "YES" << endl;
				cout << e.fi + 1 << " " << e.se + 1 << endl;
				cout << i + 1 << " " << j + 1;
				return 0;
			}
			Map[sum - a[j]] = {i, j};
		}
	}
	cout << "NO" << endl;
	return 0;
}
