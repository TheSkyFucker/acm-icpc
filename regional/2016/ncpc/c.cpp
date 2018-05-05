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

int val(char ch) {  // 
	if (ch >= '2' && ch <= '9') return ch - '1';
	if (ch == 'T') return 9;
	if (ch == 'J') return 10;
	if (ch == 'Q') return 11;
	if (ch == 'K') return 12;
	if (ch == 'A') return 13;
}
int valb(char ch) {
	if (ch == 's') return 0;
	if (ch == 'h') return 1;
	if (ch == 'd') return 2;
	if (ch == 'c') return 3;
}

int dp[100][100];
int lcp(const vector<pii> &a, const vector<pii> &b) {
	assert(sz(a) == sz(b));
	//rep(i, 0, sz(a)) printf("%d%c", a[i], " \n"[i == sz(a) - 1]);
	//rep(i, 0, sz(b)) printf("%d%c", b[i], " \n"[i == sz(b) - 1]);
	rep(i, 1, sz(a) + 1) rep(j, 1, sz(b) + 1) dp[i][j] = 0;
	rep(i, 1, sz(a) + 1) {
		rep(j, 1, sz(b) + 1) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			if (a[i - 1] == b[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	return dp[sz(a)][sz(b)];
}

vector<pii> str;
int ans = INT_MAX, n;
int tab[4] = {0, 1, 2, 3};
void solve(int mask) {
	vector<pii> tmp;
	rep(i, 0, 4) {
		int u = tab[i];
		int beg = sz(tmp);
		rep(j, 0, sz(str)) if (str[j].se == u) tmp.pb(str[j]);
		sort(tmp.begin() + beg, tmp.end());
		if (mask >> i & 1)
			reverse(tmp.begin() + beg, tmp.end());
	}
	ans = min(ans, sz(str) - lcp(str, tmp));
}

int main() {
	int n; scanf("%d", &n);
	rep(i, 0, n) {
		char a, b; scanf(" %c%c", &a, &b);
		int va = val(a);
		int vb = valb(b);
		str.pb({va, vb});
	}
	do {
		rep(i, 0, 16) solve(i);
	}	while (next_permutation(tab, tab + 4));
	printf("%d", ans);
	return 0;
}
