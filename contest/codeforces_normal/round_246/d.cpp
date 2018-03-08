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
int n;
ll cnt[N], ans[N];

int pre[N];
void ini(char str[]) {
	int n = strlen(str), tmp = -1;
	pre[0] = -1;
	rep(i, 1, n) {
		for (; ~tmp && str[tmp + 1] != str[i]; tmp = pre[tmp]);
		pre[i] = tmp += (str[tmp + 1] == str[i]);
	}
}

char str[N];
int main() {
	scanf("%s", str); n = strlen(str);
	ini(str);
	fill_n(cnt, n, 1);
	per(i, 0, n) {
		ans[pre[i]] += cnt[i];
		cnt[pre[i]] += cnt[i];
	}
	vi ans;
	for (int i = n - 1; ~i; i = pre[i]) ans.pb(i);
	printf("%d\n", sz(ans));
	per(i, 0, sz(ans)) printf("%d %lld\n", ans[i] + 1, ::ans[ans[i]] + 1);
	return 0;
}
