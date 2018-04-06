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
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e2 + 7;
int n, m;
string row[N];
bool ok(string &a, string &b) {
	if (a == b) return true;
	rep(i, 0, m) if (a[i] == '#' && a[i] == b[i]) return false;
	return true;
}
int main() {
    scanf("%d%d", &n, &m);
    rep(i, 0, n) cin >> row[i];
    rep(i, 0, n) rep(j, i + 1, n) if (!ok(row[i], row[j])) {
    	return 0 * puts("No");
	}
    puts("Yes");
	return 0;
}
