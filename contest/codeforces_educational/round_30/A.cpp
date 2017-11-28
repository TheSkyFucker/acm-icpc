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
const int N = 1e2 + 7;
int n, k, x;
void solve() {
	int ret = 0;
	rep(i, 0, n) {
		int c; scanf("%d", &c);
		if (i >= n - k) c = min(c, x);
		ret += c;
	}
	printf("%d\n", ret);
}
int main() {
	while (~scanf("%d%d%d", &n, &k, &x)) solve();
	return 0;
}
