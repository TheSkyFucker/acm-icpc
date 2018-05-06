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

int main() {
	int n; scanf("%d", &n);
	string str; cin >> str;
	map<int, int> Map;
	rep(i, 0, sz(str) - 1) {
		Map[(str[i] - 'A') * 26 + str[i + 1] - 'A']++;
	}
	int mx = 0;
	for (auto e : Map) mx = max(mx, e.se);
	for (auto e : Map) if (e.se == mx) {
		return 0 * printf("%c%c", e.fi / 26 + 'A', e.fi % 26 + 'A');
	}
	return 0;
}
