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
ll n;
void solve() {
	ll des = 1; while (des * 5ll <= n) des *= 10;
	ll tmp = des--;
	ll ans = 0;
	while (des <= n + n - 1) {
		ans += des >> 1;
		if (des > n) ans -= des - 1ll - n;
		des += tmp;
	}
	printf("%lld\n", tmp == 1 ? n * (n - 1) / 2 : ans);
}
int main() {
	while (~scanf("%lld", &n)) solve();
	return 0;
}
