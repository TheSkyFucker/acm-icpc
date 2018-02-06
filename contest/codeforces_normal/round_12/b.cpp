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
char a[N], b[N];
int cnt[N];
int main() {
	scanf(" %s", a);
	scanf(" %s", b);
	int na = strlen(a);
	int nb = strlen(b);
	rep(i, 0, na) cnt[a[i] - '0']++;
	int mi = 0; rep(i, 1, 10) if (cnt[i]) { mi = i; break; }
	rep(i, 0, nb) cnt[b[i] - '0']--;
	bool ans = true;
	rep(i, 0, 10) if (cnt[i]) ans = false;
	if (nb > 1 && b[0] == '0') ans = false;
	rep(i, 1, na - 1) if (b[i] > b[i + 1]) ans = false;
	if (b[0] - '0' != mi) ans = false;
	puts(ans ? "OK" : "WRONG_ANSWER");
	return 0;
}
