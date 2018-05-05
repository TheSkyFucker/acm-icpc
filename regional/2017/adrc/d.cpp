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
int Sqr(int d) { return d * d; }
int f(int i) {
	int ret = 0;
	while (i) {
		ret += Sqr(i % 10);
		i /= 10;
	}
	return ret;
}
void ok() { puts("HAPPY"); exit(0); }
void no() { puts("UNHAPPY"); exit(0); }
const int N = 1e3 + 7;
bool ans[N];
int n;
vi g[N];
int main() {
	scanf("%d", &n); if (f(n) == 1) ok();
	else n = f(n);
	queue<int> que;
	rep(i, 1, 1000) {
		if (f(i) == 1) ans[i] = true, que.push(i);
		g[f(i)].pb(i);
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto v : g[u]) {
			if (!ans[v]) {
				ans[v] = true;
				que.push(v);
			}
		}
	}
	if (ans[n]) ok(); else no();
	return 0;
}
