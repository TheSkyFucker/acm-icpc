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
int n;
bool ok(int d) { return d > 0 && d % 2 == 0; }
void solve() {
	scanf("%d", &n);
	puts(ok(2) && ok(n - 2) ? "YES" : "NO");
}
int main() {
	while (~scanf("%d", &n)) solve();

	return 0;
}