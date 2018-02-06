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
char str[10][10];
int main() {
	rep(i, 0, 3) scanf(" %s", str[i]);
	bool ok = true;
	rep(i, 0, 3) rep(j, i, 3) if (str[i][j] != str[3 - 1 - i][3 - 1 - j]) ok = false;
	puts(ok ? "YES" : "NO");
	return 0;
}
