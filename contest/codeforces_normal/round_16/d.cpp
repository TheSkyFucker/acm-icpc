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
int n;
char s[100];
int main() {
	scanf("%d", &n);
	int ans = 0;
	pii pre(25 * 60, 0);
	rep(i, 0, n) {
		scanf("\n%[^\n]", s);
		int h = (s[1] - '0') * 10 + s[2] - '0'; //de(h);
		int m = (s[4] - '0') * 10 + s[5] - '0'; //de(m);
		h %= 12;
		int cnt = h * 60 + m;
		if (s[7] == 'p') cnt += 12 * 60;
		if (cnt > pre.fi || (cnt == pre.fi && pre.se < 10)) {
			if (cnt == pre.fi) pre.se++; else pre = mp(cnt, 1);
		}
		else {
			ans++;
			pre = mp(cnt, 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
