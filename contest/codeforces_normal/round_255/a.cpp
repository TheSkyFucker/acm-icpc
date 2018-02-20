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
bool vis[500];
int p, n;
int main() {
	scanf("%d%d", &p, &n);
	rep(i, 0, n) {
		int x; scanf("%d", &x);
		if (vis[x % p]) return 0 * printf("%d", i + 1);
		else vis[x % p] = true;
	}
	puts("-1");
	return 0;
}
