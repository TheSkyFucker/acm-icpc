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
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, ned; cin >> n >> ned;
	string ans[4];
	rep(i, 0, 4) ans[i] = string(n, '.');
	int m = n >> 1;
	rep(i, 1, 3) rep(j, 1, m + 1) if (ned >= 2 - (j == m)) {
		ned -= 2 - (j == m);
		ans[i][j] = ans[i][n - 1 - j] = '#';
	}
	cout << "YES" << endl;
	rep(i, 0, 4) cout << ans[i] << endl;

	return 0;
}
