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
const int N = 1e3 + 7, MOD = 1e9 + 7;
int C[N][N], pw2[N], n, m;
bool v[N];
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int main() {
	rep(i, 0, N) C[i][0] = 1;
	rep(i, 1, N) rep(j, 1, i + 1) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	pw2[0] = 1;  rep(i, 1, N) pw2[i] = add(pw2[i - 1], pw2[i - 1]);
	//rep(i, 0, 32) de(pw2[i]);
	//rep(i, 0, 10) rep(j, 0, i + 1) printf("%d%c", C[i][j], " \n"[j == i]);
	//return 0;
	scanf("%d%d", &n, &m);
	rep(i, 0, m) {
		int p; scanf("%d", &p); v[p] = true;
	}
	vi vu;
	int emp = 0;
	for (int l = 1, r; l <= n; l = r) {
		if (v[l]) { r = l + 1; continue; }
		r = l; while (r <= n && !v[r]) r++;
		vu.pb(r - l);
		emp += r - l;
	}
	int ans = 1;
	int b = !v[1], e = sz(vu);
	if (!v[n]) e--;
	rep(i, b, e) ans = mul(ans, pw2[vu[i] - 1]);
	int tmp = 0;
	for (auto e : vu) {
	//	dd(emp - tmp); de(e);
		ans = mul(ans, C[emp - tmp][e]);
		tmp += e;
	}
	printf("%d\n", ans);

    
	return 0;
}
