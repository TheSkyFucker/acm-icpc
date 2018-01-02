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
const int N = 1e3 + 7;
int n, m, c;
void answer(int p) {
	printf("%d\n", p);
	fflush(stdout);
}

int tab[N], nl, nr;
void solve() {
	nl = nr = 0;
	rep(i, 0, m) {
		int d; scanf("%d", &d);
		if (d * 2 <= c) {
			int p = upper_bound(tab, tab + nl, d) - tab;
			if (p == nl) tab[nl++] = d;
			else tab[p] = d;
			answer(p + 1);
		}
		else {
			int p = lower_bound(tab + n - nr, tab + n , d) - tab - 1;
			if (p == n - nr - 1) tab[n - (++nr)] = d;
			else tab[p] = d;
			answer(p + 1);
		}
		if (nl + nr == n) return;
	}
}
			
int main() {
	~scanf("%d%d%d", &n, &m, &c);
	solve();
	return 0;
}
