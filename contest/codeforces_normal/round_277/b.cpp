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
const int N = 5e2 + 7;
int n, m, a[N][N], b[N][N];
int zro_row[N], zro_col[N];
int ans_row[N], ans_col[N];
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n) rep(j, 0, m) {
		scanf("%d", &a[i][j]);
		if (a[i][j] == 0) {
			zro_row[i] = true;
			zro_col[j] = true;
		}
	}
	rep(i, 0, n) rep(j, 0, m) {
		if (zro_row[i] || zro_col[j]) b[i][j] = 0; else b[i][j] = 1;
		if (b[i][j]) {
			ans_row[i] = true;
			ans_col[j] = true;
		}
	}
	rep(i, 0, n) rep(j, 0, m) {
		int _a;
		if (ans_row[i] || ans_col[j]) _a = 1; else _a = 0;
		if (_a != a[i][j]) return 0 * puts("NO");
	}
	puts("YES");
	rep(i, 0, n) rep(j, 0, m) printf("%d%c", b[i][j], " \n"[j == m - 1]);
	return 0;
}
