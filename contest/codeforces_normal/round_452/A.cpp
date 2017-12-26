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
int n, n1, n2;
void solve() {
	n1 = n2 = 0;
	rep(i, 0, n) {
		int d; scanf("%d", &d);
		n1 += d == 1;
		n2 += d == 2;
	}
	int mi = min(n1, n2);
	n1 -= mi;
	n2 -= mi;
	printf("%d\n", mi + n1 / 3);
}
int main() {
	while (~scanf("%d", &n)) solve();

	return 0;
}
