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
const int N = 1e5 + 7;
int n, p;
char str[N];
int main() {
	scanf("%d%d", &n, &p); p--;
	scanf("%s", str);
	int l = 0, r = n - 1;
	while (l <= r && str[l] == str[r]) l++, r--;
	if (l > r) return 0 * printf("0");
	int ans = min(abs(p - l), abs(p - r));
	int mi = N, mx = 0;
	rep(i, 0, n) {
		if (l + i >= r - i) break;
		if (str[l + i] != str[r - i]) {
			mi = min(mi, i);
			mx = max(mx, i);
		}
	}
	ans = min(ans, min(abs(l + mx - p), abs(r - mx - p)));
	ans += mx - mi;
	while (l < r) {
		if (str[l] != str[r])
			ans += min((str[r] + 26 - str[l]) % 26, (str[l] + 26 - str[r]) % 26);
		l++; r--;
	}
	
  printf("%d", ans); 
	return 0;
}
