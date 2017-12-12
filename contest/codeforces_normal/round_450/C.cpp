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
int n, p[N], v[N];
void solve() {
	fill_n(v + 1, n, 0);
	int mx1 = -1, mx2 = -1;
	rep(i, 0, n) {
		int dig; scanf("%d" ,&dig);
		if (dig > mx2 && dig < mx1) v[mx1]++;
		else if (dig > mx1) v[dig]--;
		if (dig > mx1) {
			mx2 = mx1;
			mx1 = dig;
		} else if (dig > mx2) {
			mx2 = dig;
		}
	}
	pii mx = {- n - 1, -1};
	rep(i, 1, n + 1) mx = max(mx, {v[i], -i});
	printf("%d\n", -mx.se);
}
		
int main() {
	while (~scanf("%d", &n)) solve();
	return 0;
}
