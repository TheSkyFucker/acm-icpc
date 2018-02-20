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
const int N = 1e3 + 7;
char str[N];
int val[N], n, m;
int main() {
	scanf(" %s", str);
	n = strlen(str);
	scanf("%d", &m);
	rep(i, 0, 26) scanf("%d", &val[i]);
	int ans = 0;
	rep(i, 0, n) ans += val[str[i] - 'a'] * (i + 1);
	int mx = 0; rep(i, 0, 26) mx = max(mx, val[i]);
	rep(i, 0, m) ans += mx * (n + 1 + i);
	printf("%d", ans);
	return 0;
}
