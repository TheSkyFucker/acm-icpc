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
const int N = 1e6 + 7;
int pre[N];
void ini(int str[], int n) {
	int tmp = -1;
	pre[0] = -1;
	rep(i, 1, n) {
		for (; ~tmp && str[tmp + 1] != str[i]; tmp = pre[tmp]);
		pre[i] = tmp += (str[tmp + 1] == str[i]);
	}
}
int n, a[N], ned[N];
int main() {
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d", a + i);
  reverse(a, a + n);
	ini(a, n);
	pii ans = {INT_MAX, 0};
	rep(i, 0, n) {
		ned[i] = i - pre[i];
		if (pre[i] >= ned[i]) {
			if (ned[pre[i]] != ned[i]) ned[i] = -1;
		}
		if (~ned[i])
			ans = min(ans, {ned[i] + n - 1 - i, ned[i]});
	}
  printf("%d %d\n", ans.fi - ans.se, ans.se);
	return 0;
}
