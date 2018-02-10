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
int n;
int main() {
	scanf("%d", &n);
	const int nag = 0, zro = 1, pos = 2;
	vi v[3];
	rep(i, 0, n) {
		int a; scanf("%d", &a);
		if (!a) v[zro].pb(a);
		else if (a > 0) v[pos].pb(a);
		else v[nag].pb(a);
	}
	if (!sz(v[pos])) {
		v[pos].pb(v[nag].back()); v[nag].pop_back();
		v[pos].pb(v[nag].back()); v[nag].pop_back();
	}
	if (sz(v[nag]) % 2 == 0) {
		v[zro].pb(v[nag].back()); v[nag].pop_back();
	}
	printf("%d", sz(v[nag]));   for (auto e : v[nag]) printf(" %d", e);
	printf("\n%d", sz(v[pos])); for (auto e : v[pos]) printf(" %d", e);
	printf("\n%d", sz(v[zro])); for (auto e : v[zro]) printf(" %d", e);
    
	return 0;
}
