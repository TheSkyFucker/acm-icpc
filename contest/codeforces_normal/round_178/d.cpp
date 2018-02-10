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
const int N = 1e5 + 7;
int n, m, sx, sy;
char dir[4];
int main() {
	scanf("%d%d%d%d %s", &n, &m, &sx, &sy, dir);
	int dx = dir[0] == 'U' ? -1 : 1;
	int dy = dir[1] == 'L' ? -1 : 1;
	int remain = n + m - 2;
	set<pii> Set;
	if (sx == 1 || sx == n || sy == 1 || sy == m) {
		remain--;
		Set.insert({sx, sy});
	}
	ll ans = 0;
	rep(i, 0, 4 * N) {
		int step = pw(30);
		step = min(step, dx == 1 ? n - sx : sx - 1);
		step = min(step, dy == 1 ? m - sy : sy - 1);
		ans += step;
		sx += dx * step;
		sy += dy * step;
		if ((sx == 1 && dx == -1) || (sx == n && dx == 1)) dx *= -1;
		if ((sy == 1 && dy == -1) || (sy == m && dy == 1)) dy *= -1;
		if (Set.find({sx, sy}) == Set.end()) {
			if (!--remain) { printf("%lld\n", ans + 1); return 0; } 
			Set.insert({sx, sy});
		}
		//dd(sx); dd(sy); de(remain);
	}
	puts("-1");
	return 0;
}
