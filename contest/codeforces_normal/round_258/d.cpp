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
const int N = 1e5 + 7;
char str[N];
int n;
int main() {
	scanf(" %s", str);
	n = strlen(str);
	ll ans[2] = {0, 0}, cnt[2][2] = {{0, 0}, {0, 0}};
	rep(i, 0, n) {
		cnt[str[i] - 'a'][i & 1]++;
		rep(j, 0, 2) ans[(i & 1) ^ j ^ 1] += cnt[str[i] - 'a'][j];
	}
	printf("%lld %lld", ans[0], ans[1]);
	return 0;
}
