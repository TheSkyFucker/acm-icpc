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
int n, m;
void solve() {
	int tot = 0;
	bool has = false;
	rep(i, 1, n + 1) {
		tot += i * 2;
		if (i % m == 0) {
			if (has) printf(" "); else has = true;
			printf("%d", tot / m);
			tot = 0;
		}
	}
	if (tot) {
		if (has) printf(" ");
		printf("%d", tot / (n % m));
	}
	printf("\n");
}
int main() {
	while (~scanf("%d%d", &n, &m)) solve();

	return 0;
}
