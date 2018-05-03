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
vector<char> str[N];
int n;
int main() {
	scanf("%d", &n);
	set<vector<char> > Set;
	rep(i, 0, n) {
		string tmp; cin >> tmp;
		rep(j, 0, sz(tmp)) str[i].pb(tmp[j]);
		sort(all(str[i]));
		str[i].erase(unique(all(str[i])), str[i].end());
		Set.insert(str[i]);
	}
	printf("%d", sz(Set));
	return 0;
}
