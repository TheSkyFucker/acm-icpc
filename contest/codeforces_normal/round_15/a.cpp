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
const int N = 1e3 + 7;
int n, m;
pii p[N];
int main() {
	scanf("%d%d", &n, &m); m <<= 1;
	rep(i, 0, n) scanf("%d%d", &p[i].fi, &p[i].se), p[i].fi <<= 1;
	sort(p, p + n);
	int ans = 2;
	rep(i, 1, n) {
		int tmp = p[i].fi - p[i - 1].fi - p[i - 1].se - p[i].se;
		if (tmp > m) ans += 2;
		else if (tmp == m) ans ++;
	}
	printf("%d\n", ans);
	


    
	return 0;
}
