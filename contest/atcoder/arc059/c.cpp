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
const int N = 1e2 + 7;
int n, a[N];
int Sqr(int d) { return d * d; }
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	int ans = INT_MAX;
	rep(mid, -100, 101) {
		int tmp = 0;
		rep(i, 0, n) tmp += Sqr(a[i] - mid);
		ans = min(ans, tmp);
	}
	cout << ans;
	return 0;
}
