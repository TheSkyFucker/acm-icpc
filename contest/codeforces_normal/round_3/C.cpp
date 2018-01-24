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
char bod[4][4];
int cnt[1000], win[1000];
void solve() {
	cnt['X'] = cnt['0'] = cnt['.'] = 0;
	rep(i, 1, 3) scanf(" %s", bod[i]);
	rep(i, 0, 3) rep(j, 0, 3) cnt[bod[i][j]]++;
	win['X'] = win['0'] = 0;
	rep(i, 0, 3) {
		if (bod[i][0] == '.') continue;
		if (bod[i][1] != bod[i][0] || bod[i][2] != bod[i][0]) continue;
		win[bod[i][0]] = true;
	}
	rep(j, 0, 3) {
		if (bod[0][j] == '.') continue;
		if (bod[1][j] != bod[0][j] || bod[2][j] != bod[0][j]) continue;
		win[bod[0][j]] = true;
	}
	if (bod[0][0] != '.' && bod[1][1] == bod[0][0] && bod[2][2] == bod[0][0]) win[bod[0][0]] = true;
	if (bod[2][0] != '.' && bod[1][1] == bod[2][0] && bod[0][2] == bod[2][0]) win[bod[2][0]] = true;
	if (win['X'] && win['0']) { puts("illegal"); return; }
	if (cnt['X'] < cnt['0'] || cnt['X'] > cnt['0'] + 1) { puts("illegal"); return; }
	if (win['X']) { puts(cnt['X'] == cnt['0'] + 1 ? "the first player won" : "illegal"); return; }
	if (win['0']) { puts(cnt['X'] == cnt['0'] + 0 ? "the second player won" : "illegal"); return; }
	if (!cnt['.']) { puts("draw"); return; }
	if (cnt['X'] == cnt['0']) { puts("first"); return; }
	if (cnt['X'] == cnt['0'] + 1) { puts("second"); return; }
	puts("illegal");
}
int main() {
	while (~scanf(" %s", bod[0])) solve();

	return 0;
}