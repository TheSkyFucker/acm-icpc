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
int n;
void solve() {
	int cntl = 0, cntr = 0;
	rep(i, 0, n) {
		int x, y; scanf("%d%d", &x, &y);
		if (x < 0) cntl++;
		else cntr++;
	}
	puts(min(cntl, cntr) <= 1 ? "Yes" : "No");
}
int main() {
	while (~scanf("%d", &n)) solve();
	return 0;
}
