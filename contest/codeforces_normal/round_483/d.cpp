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
const int N = 2e5 + 8;
int n, x[N], dp[N], pre[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> x[i];
	set<int> S;
	rep(i, 0, n) S.insert(x[i]);
	rep(i, 0, n) {
		rep(j, 0, 31) {
			if (S.find(x[i] + pw(j)) != S.end()) 
				if (S.find(x[i] - pw(j)) != S.end()) {
					cout << 3 << endl;
					cout << x[i] - pw(j) << " " << x[i] << " " << x[i] + pw(j) << endl;
					return 0;
				}
		}
	}
	rep(i, 0, n) {
		rep(j, 0, 31) {
			if (S.find(x[i] + pw(j)) != S.end()) {
				cout << 2 << endl;
				cout << x[i] << " " << x[i] + pw(j) << endl;
				return 0;
			}
		}
	}
	cout << 1 << endl << x[0];
	return 0;
}
