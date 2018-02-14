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
int na, nb;
int gao(int a, int b) {
	int ret = 0;
	int cnt[2] = {a - 1, b}, p = 0;
	rep(i, 1, na + nb) {
		if (i & 1) {
			if (cnt[p ^ 1]) {
				cnt[p ^ 1]--;
				p ^= 1;
				ret++;
			}
			else cnt[p]--;
		}
		else if (cnt[p]) cnt[p]--;
		else {
			cnt[p ^ 1]--;
			p ^= 1;
			ret++;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &na, &nb);
	int ans2 = min(gao(na, nb), gao(nb, na));
	printf("%d %d", na + nb - 1 - ans2, ans2);
	return 0;
}
