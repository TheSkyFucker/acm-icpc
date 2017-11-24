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
const int N = 3e5 + 7;
struct UF {
	static const int N = 3e5 + 7;
	int far[N], siz[N];
	void init() { rep(i, 0, N) far[i] = i, siz[i] = 1; }
	int  getf(int d) { return far[d] == d ? d : far[d] = getf(far[d]); }
	bool same(int a, int b) { return getf(a) == getf(b); }
	void comb(int a, int b) {
		if (same(a = getf(a), b = getf(b))) return;
		far[a] = b;
		siz[b] += siz[a];
	}
}	uf;
///-----
int n;
bool vis[N];
int main() {

	//read
	scanf("%d", &n); uf.init();
	printf("1");
	int ans = 1;
	vis[n + 1] =true;
	rep(i, 0, n) {
		int dig; scanf("%d", &dig); vis[dig] = true;
		ans++;
		if (dig > 1 && vis[dig - 1]) uf.comb(dig - 1, dig);
		if (vis[dig + 1]) {
			if (uf.getf(dig + 1) == n + 1) ans -= uf.siz[dig];
			uf.comb(dig, dig + 1);
		}
		printf(" %d", ans);
	}
	

	
	return 0;

}
