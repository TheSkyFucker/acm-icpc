
#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define debug(x) cout << #x << " => " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

///----------------------------------------------
const int N = 1e6 + 100;
const int MOD = 1e9 + 7;
int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int c[N][30];
int pw2[N];

int x, y;
void solve() {
	scanf("%d%d", &x, &y);
	int ans = pw2[y - 1];
	for (int i = 2; i * i <= x; i++) if (x % i == 0) {
		int cnt = 0; while (x % i == 0) x /= i, cnt++;
		ans = mul(ans, c[y + cnt - 1][cnt]);
	}
	if (x > 1) ans = mul(ans, y);
	printf("%d\n", ans);
}
	

int main() {
	pw2[0] = 1; rep(i, 1, N) pw2[i] = add(pw2[i - 1], pw2[i - 1]);
	rep(i, 0, N) c[i][0] = 1;
	rep(i, 1, N) rep(j, 1, min(i + 1, 25)) c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
	int tcase = 0; scanf("%d", &tcase);
	rep(icase, 0, tcase) solve();
	return 0;

}
