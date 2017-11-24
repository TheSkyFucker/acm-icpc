#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
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

const int N = 1e5 + 7;
vi s[N];
vi G[N];
int ned[N], n, m;
void error() { puts("No"); exit(0); }
int main() {

	//read
	scanf("%d%d", &n, &m);
	rep(i, 0, n) {
		int sz; scanf("%d", &sz);
		s[i].resize(sz);
		rep(j, 0, sz(s[i])) scanf("%d", &s[i][j]);
	}
	
	//work
	memset(ned, -1, sizeof(ned));
	rep(i, 0, n - 1) {
		int len = min(sz(s[i]), sz(s[i + 1]));
		bool ok = false;
		rep(j, 0, len) if (s[i][j] != s[i + 1][j]) {
			int a = s[i][j];
			int b = s[i + 1][j];
			if (a > b) {
				if (~ned[a] && ned[a] != 1) error(); 
				if (~ned[b] && ned[b] != 0) error();
				ned[a] = 1;
				ned[b] = 0;
			} else G[b].pb(a);
			ok = true;
			break;
		}
		if (!ok && sz(s[i]) > sz(s[i + 1])) error();
	}
	
	//work
	//rep(i, 1, m + 1) de(ned[i]);
	rep(i, 1, m + 1) if (ned[i] == 1) {
		queue<int> que; que.push(i);
		while (!que.empty()) {
			int u = que.front(); que.pop();
			rep(_v, 0, sz(G[u])) {
				int v = G[u][_v]; if (ned[v] == 0) error();
				if (!~ned[v]) {
					ned[v] = 1;
					que.push(v);
				}
			}
		}
	}

	
	puts("Yes");
	vi ans; rep(i, 1, m + 1) if(ned[i] == 1) ans.pb(i);
	printf("%d\n", sz(ans));
	rep(i, 0, sz(ans)) printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);


	
	return 0;

}
