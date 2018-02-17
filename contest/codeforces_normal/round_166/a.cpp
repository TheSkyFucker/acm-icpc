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
bool ck(int n) {
	vi v; while (n) v.pb(n % 10), n /= 10;
	sort(all(v));
	rep(i, 1, sz(v)) if (v[i] == v[i - 1]) return false;
	return true;
}
int main() {
	scanf("%d", &n);
	while (!ck(++n));
	printf("%d", n);
	return 0;
}
