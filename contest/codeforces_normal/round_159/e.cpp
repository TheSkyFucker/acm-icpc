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
int n, m, des[N];
vector<pii> que[N];

struct Fenwick {
	static const int N = ::N;
	int n, a[N];
	void ini(int _n = N - 1) { n = _n; }
	void add(int p, int v) { for (; p <= n; p += p & -p) a[p] += v; }
	int qry(int p) { int r = 0; for (; p; p -= p & -p) r += a[p]; return r; }
	int qry(int l, int r) { return qry(r) - qry(l - 1); } 
}	fen;
int myabs(int d) { return d > 0 ? d : -d; }
ll ans[N];
int main() {
	scanf("%d%d", &n, &m);
	priority_queue<pair<int, pii> > stk;
	rep(i, 0, n) {
		int t, s; scanf("%d%d%d", &t, &s, &des[i]);
		stk.push({-t, {s, i}});
	}
	ll tim = 0;
	int cur = 1, fin = 0;
	fen.ini(m);
	set<int> s;
	while (fin < n) {
		int cntl = fen.qry(1, cur);
		int cntr = fen.qry(cur, m);
		//dd(cntl); de(cntr);
		if (!cntl && !cntr) {
			tim = -stk.top().fi;
		}
		else {
			int des;
			if (cntl <= cntr) des = *s.upper_bound(cur);
			else {
				auto it = s.lower_bound(cur);
				des = *--it;
			}
			int det = myabs(des - cur);
			if (!stk.empty())
				det = min((ll)det, -stk.top().fi - tim);
			cur += cntl <= cntr ? det : -det;
			tim += det;
		}
		while (!stk.empty() && -stk.top().fi == tim) {
			auto e = stk.top(); stk.pop();
			que[e.se.fi].pb({0, e.se.se});
			s.insert(e.se.fi);
			fen.add(e.se.fi, 1);
		}
		s.erase(cur);
		for (auto e : que[cur]) {
			fen.add(cur, -1);
			if (e.fi == 0) {
				int d = ::des[e.se];
				que[d].pb({1, e.se});
				s.insert(d);
				fen.add(d, 1);
			}
			else {
				fin++;
				ans[e.se] = tim;
			}
		}
		que[cur].clear();
	}
	rep(i, 0, n) printf("%lld\n", ans[i]);
	return 0;
}
