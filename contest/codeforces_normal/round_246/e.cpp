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
char s[N][N];
int n, m;
char getch(int i, int j) {
	int ban[5]; fill_n(ban, 5, 0);
	static const int g[3][2] = {{-1, 0}, {0, -1}, {0, 1}};
	rep(d, 0, 3) {
		char ch = s[i + g[d][0]][j + g[d][1]];
		if (ch == '#') continue;
		if (ch - 'A' > 4) continue;
		ban[ch - 'A'] = 1;
	}
	rep(i, 0, 5) if (!ban[i]) return 'A' + i;
}
		
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n + 2) rep(j, 0, m + 2) s[i][j] = '#';
	rep(i, 1, n + 1) rep(j, 1, m + 1) if (s[i][j] == '#') {
		s[i][j] = getch(i, j);
		int l = 1;
		while (j + l <= m && i + l <= n && s[i][j + l] == '#' && getch(i, j + l) > s[i][j]
			&& s[i - 1][j + l] != s[i][j] && s[i + l][j - 1] != s[i][j]) {
			s[i][j + l] = s[i][j];
			l++;
		}
		rep(ii, 0, l) rep(jj, 0, l) s[i + ii][j + jj] = s[i][j];
	}
	rep(i, 1, n + 1) {
		s[i][m + 1] = '\0';
		puts(s[i] + 1);
	}
	return 0;
}
