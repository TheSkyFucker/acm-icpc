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
const int N = 5e5 + 7;
int n, a[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	vi ans;
	rep(i, 0, n) {
		stack<int> stk;
		map<int, int> pre, cnt;
		for (int &j = i; j < n; j++) {
			if (pre.count(a[j])) {
				rep(j, 0, 2) {
					ans.pb(pre[a[i]]);
					ans.pb(a[i]);
				}
				break;
			}
			while (!stk.empty() && (cnt[a[i]] > 1 || (cnt[a[i]] == 1 && stk.top() !=	a[i]))) {
				int u = stk.top(); stk.pop();
				pre[u] = a[i];
				cnt[u]--;
			}
			stk.push(a[i]);
			cnt[a[i]]++;
		}
	}
	printf("%d\n", sz(ans));
	rep(i, 0, sz(ans)) printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
	return 0;
}
