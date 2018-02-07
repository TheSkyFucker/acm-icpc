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
char str[N][N];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%s", str[i]);
	int sx = n, sy = m, tx = 0, ty = 0;
	rep(i, 0, n) rep(j, 0, m) if (str[i][j] == '*') {
		sx = min(sx, i);
		tx = max(tx, i);
		sy = min(sy, j);
		ty = max(ty, j);
	}
	rep(i, sx, tx + 1) rep(j, sy, ty + 1) {
		printf("%c", str[i][j]);
		if (j == ty) puts("");
	}
	return 0;
}
