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
const int N = 2e5 + 7;
char s[N]; int n;
int main() {
	scanf("%s", s); n = strlen(s);
	vector<pair<char, int> > v;
	for (int l = 0, r; l < n; l = r) {
		r = l; while (r < n && s[r] == s[l]) r++;
		v.pb({s[l], min(2 - (!v.empty() && v.back().se == 2), r - l)});
	}
	for (auto e : v) {
		rep(i, 0, e.se) putchar(e.fi);
	}
	return 0;
}
