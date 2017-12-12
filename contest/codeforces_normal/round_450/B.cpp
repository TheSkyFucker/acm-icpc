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
const int N = 1e5 + 7;
int a, b, c;
bool has[N];
int ans[N], an;
void solve() {
	fill_n(has, b, false);
	for (int ans = 1; ; ans++) {
		if (has[a % b]) break;
		else has[a % b] = true;
		a = (a % b) * 10;
		if (a / b == c) {
			printf("%d\n", ans);
			return;
		}
	}
	puts("-1");
}
	
int main() {
	while (~scanf("%d%d%d", &a, &b, &c)) solve();
	return 0;
}
