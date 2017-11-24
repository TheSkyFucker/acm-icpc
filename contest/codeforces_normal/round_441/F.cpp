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
const int N = 2e5 + 7;
struct UF {
	static const int N = ::N;
	int far[N], siz[N], n;
	void init() { per(i, 0, N) far[i] = i, siz[i] = 1; }
	int  getf(int d) { return far[d] == d ? d : far[d] = getf(far[d]); }
	bool same(int a, int b) { return getf(a) == getf(b); }
	void comb(int a, int b) {
		if (same(a = getf(a), b = getf(b))) return;
		far[a] = b;
		siz[b] += siz[a];
	}
}	uf;
	
int n, m;
pair<int, pii> p[N];
int main() {

	//read
	scanf("%d%d", &n, &m);
	rep(i, 0, m) scanf("%d%d%d", &p[i].se.fi, &p[i].se.se, &p[i].fi);
	
	//work
	sort(p, p + m); uf.init();
	int ans = 0;
	per(i, 0, m) {
		int a = uf.getf(p[i].se.fi), b = uf.getf(p[i].se.se);
		if (uf.siz[a] + uf.siz[b] == 0) continue; else ans += p[i].fi;
		uf.comb(b, a);
		uf.siz[a]--;
	}
	printf("%d", ans);
	
	return 0;

}
