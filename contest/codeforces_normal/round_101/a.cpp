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
const int N = 1e2 + 7;
char str[N];
int cnt[N];
void gao(char *str, int v) {
	int n = strlen(str);
	rep(i, 0, n) cnt[str[i] - 'A'] += v;
}
int main() {
	rep(i, 0, 2) {
		scanf(" %s", str);
		gao(str, 1);
	}
	scanf(" %s", str);
	gao(str, -1);
	rep(i, 0, 26) if (cnt[i] != 0) return 0 * puts("NO");
	puts("YES");
	return 0;
}
