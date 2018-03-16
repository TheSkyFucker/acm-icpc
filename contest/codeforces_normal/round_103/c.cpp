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
int has[1000], err = 0;

void gao(char ch, int v) {
	if (ch == '?') return;
	if (has[ch] < 0) err--;
	has[ch] += v;
	if (has[ch] < 0) err++;
}
	
int main() {
	string str, d; cin >> str >> d;
	if (sz(str) < sz(d)) return 0 * puts("0");
	rep(i, 0, sz(d)) has[d[i]]++;
	rep(i, 0, sz(d)) gao(str[i], -1);
	int ans = !err;
	rep(i, sz(d), sz(str)) {
		gao(str[i], -1);
		gao(str[i - sz(d)], 1);
		ans += !err;
	}
	printf("%d", ans);
	return 0;
}
