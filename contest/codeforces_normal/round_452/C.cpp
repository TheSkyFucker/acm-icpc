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
	vi v;
	rep(i, 0, n) if (i % 4 == 0 || i % 4 == 3) v.pb(n - i);
	puts(n % 4 == 1 || n % 4 == 2 ? "1" : "0");
	printf("%d ", sz(v));
	per(i, 0, sz(v)) printf("%d%c", v[i], " \n"[i == 0]);
}

int main() {
	while (~scanf("%d", &n)) solve();
	return 0;
}
