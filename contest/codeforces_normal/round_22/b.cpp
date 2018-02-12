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
char a[N][N];
int s[N][N], n, m;
int sum(int sx, int sy, int tx, int ty) {
	return s[tx][ty] - s[sx - 1][ty] - s[tx][sy - 1] + s[sx - 1][sy - 1];
}
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n + 1) scanf(" %s", a[i] + 1);
	rep(i, 1, n + 1) rep(j, 1, m + 1)
		s[i][j] = s[i - 1][j] + s[i][j - 1] + (a[i][j] == '1') - s[i - 1][j - 1];
	int ans = 0;
	rep(a, 1, n + 1) rep(b, 1, m + 1)
		rep(sx, 1, n + 2 - a) rep(sy, 1, m + 2 - b)
			if (sum(sx, sy, sx + a - 1, sy + b - 1) == 0)
				ans = max(ans, 2 * a + 2 * b);
	printf("%d\n", ans);
    
	return 0;
}
