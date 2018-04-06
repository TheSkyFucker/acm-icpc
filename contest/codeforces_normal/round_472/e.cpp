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
const int N = 1e4 + 7;
int n, l, r, w[N], dp[N];
int main() {
	scanf("%d%d%d", &n, &l, &r);
	int sum = 0;
	rep(i, 0, n) scanf("%d", w + i), sum += w[i];
	int newl = sum - r, newr = sum - l;
	l = newl, r = newr;
	fill_n(dp + 1, sum, -1);
	vector<pii> v;
	rep(i, 0, n) {
		int a; scanf("%d", &a);
		v.pb({-a, w[i]});
	}
	sort(all(v)); reverse(all(v));
	for (auto e : v) {
		int v, w;
		tie(v, w) = e;
		per(j, w, sum + 1) {
			if (!~dp[j - w]) continue;
			dp[j] = max(dp[j], dp[j - w] + (v && j >= l && j <= r));
		}
	}
	cout << *max_element(dp, dp + 1 + sum);
	return 0;
}
