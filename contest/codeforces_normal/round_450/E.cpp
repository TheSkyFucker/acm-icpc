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
const int N = 1e5  + 7;
int n, m; char str[N];
int suma[2][N], sumb[2][N], sumc[N];
int gao(int p) {
	if (p < m) return -1;
	if (m % 2 == 0) {
		if (suma[p & 1][p] - suma[p & 1][p - m]) return -1;
		if (sumb[(p - 1) & 1][p - 1] - sumb[(p - 1) & 1][p - m]) return -1;
	} else {
		if (sumb[p & 1][p] - sumb[p & 1][p - m]) return -1;
		if (suma[(p - 1) & 1][p - 1] - suma[(p - 1) & 1][p - m]) return -1;
	}
	return sumc[p] - sumc[p - m];
}
int can[N], ned[N];
void solve() {
	scanf(" %s", str + 1); scanf("%d", &m);
	rep(i, 1, n + 1) {
		suma[i & 1][i] = str[i] == 'a';
		sumb[i & 1][i] = str[i] == 'b';
		sumc[i] = str[i] == '?';
	}
	rep(i, 0, 2) rep(j, 1, n + 1) {
		suma[i][j] += suma[i][j - 1];
		sumb[i][j] += sumb[i][j - 1];
	}
	rep(i, 1, n + 1) sumc[i] += sumc[i - 1];
	rep(i, 1, n + 1) {
		int cost = gao(i);
		if (!~cost) {
			can[i] = can[i - 1];
			ned[i] = ned[i - 1];
		} else if (can[i - m] == can[i - 1]) {
			can[i] = can[i - 1] + 1;
			ned[i] = ned[i - m] + cost;
		} else {
			can[i] = can[i - 1];
			ned[i] = min(ned[i - 1], ned[i - m] + cost);
		}
	}
	//rep(i, 1, n + 1) de(can[i]);
	printf("%d\n", ned[n]);
}

int main() {
	while (~scanf("%d", &n)) solve();
	return 0;
}
