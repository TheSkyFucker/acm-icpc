
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

struct GuassLB {
  static const int B = 20;
  ll b[B] , sz;
  void ini()  { fill_n(b, B, 0); }
  bool add(ll a) {
    per(i, 0, B) if((a >> i) & 1) {
      if (b[i]) a ^= b[i]; else {
        b[i] = a;
        per(j, 0, i) if(b[j] && (b[i] & pw(j))) b[i] ^= b[j];
        per(j, i + 1, B) if (b[j] & pw(i)) b[j] ^= b[i];
		return true;
      }
    }
    return false;
  }
  bool ok(ll a) {
  	  per(i, 0, B) if ((a >> i) & 1) {
  	  	  if (b[i]) a ^= b[i]; else return false;
	  }
	  return true;
  }
}	gs;

const int N = 1e5 + 7, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) {return 1ll * a * b % MOD; }
vector<pii> g[N];
int n, q, a[N], ans[N], dp[N];
int main() {
    scanf("%d%d", &n, &q);
    rep(i, 1, n + 1) scanf("%d", a + i);
    rep(i, 0, q) {
    	int l, x; scanf("%d%d", &l, &x);
    	g[l].pb({x, i});
	}
    gs.ini();
    dp[0] = 1;
    rep(i, 1, n + 1) {
    	int &d = dp[i];
    	d = dp[i - 1];
    	if (!gs.add(a[i])) d = add(d, d);
    	for (auto e : g[i]) {
    		if (gs.ok(e.fi)) ans[e.se] = dp[i];
		}
	}
    rep(i, 0, q) printf("%d\n", ans[i]);
	return 0;
}
