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
	scanf("%d", &n); vi a(n);
	rep(i, 0, n) scanf("%d", &a[i]);
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	if (sz(a) < 2) puts("NO");
	else printf("%d", a[1]);
	return 0;
}
