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

//------
const int N = 1e2 + 7;
int n;
ll v[N];
void solve() {
	fill_n(v, N, 0);
	ll cur = 1, ans = 1;
	rep(i, 1, n) {
		cur += v[i];
		v[i + 3] += cur;
		ans += cur;
	}
	printf("%lld\n", ans);
}
int main() {
	while (~scanf("%d", &n) && n) solve();

	return 0;
}
