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
void ini(string s, int p[], int dp[]) {
	int t = -1; p[0] = dp[0] = -1;
	rep(i, 1, sz(s)) {
		while (~t && s[t + 1] != s[i]) t = p[t];
		p[i] = t += (s[t + 1] == s[i]);
		if (p[i] + 1 == i - p[i] || dp[p[i]] == i - p[i]) dp[i] = i - p[i];
		else dp[i] = -1;
	}
}
const int N = 5e5 + 7;
int p1[N], p2[N], d1[N], d2[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  string s1; cin >> s1;
  string s2; s2 = s1; reverse(all(s2));
  ini(s1, p1, d1);
  ini(s2, p2, d2);
	if (!~d1[sz(s1) - 1]) { cout << "1\n1"; return 0; }
	int ans = 0;
	rep(i, 0, sz(s1) - 1) if (!~d1[i] && !~d2[sz(s1) - i - 2]) ans++;
	if (ans) cout << 2 << endl << ans;
	else cout << sz(s1) << endl << 1;
	return 0;
}
