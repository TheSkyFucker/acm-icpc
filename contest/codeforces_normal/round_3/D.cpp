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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
const int N = 1e5 + 7;
char str[N];
int n, val[N];
void solve() {
	n = strlen(str);
	ll ans = 0;
	rep(i, 0, n) if (str[i] == '?') {
		int a, b; scanf("%d%d", &a, &b);
		val[i] = a - b;
		ans += b;
	}
	priority_queue<pii> stk;
	int sum = 0;
	rep(i, 0, n) {
		if (str[i] == '?') {
			str[i] = ')';
			stk.push({-val[i],  i});
		}
		sum += (str[i] == '(') - (str[i] == ')');
		if (sum < 0) {
			if (stk.empty()) break;
			sum += 2;
			ans += -stk.top().fi;
			str[stk.top().se] = '(';
			stk.pop();
		}
	}
	printf("%lld\n", sum == 0 ? ans : -1);
	if (sum == 0) puts(str);
}
			
int main() {
	while (~scanf(" %s", str)) solve();

	return 0;
}