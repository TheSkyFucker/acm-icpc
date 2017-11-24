#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define debug(x) cout << #x << " => " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

///----------------------------------------------
int n, m;
int solve() {
	scanf("%d%d", &n, &m);
	int cur = 0, can = 0, ans = 0;
	rep(i, 0, n) {
		int c; scanf("%d", &c);
		cur += c;
		if (c > 0) {
			if (cur > m) {
				if ((can -= cur - m) < 0) return -1;
				cur = m;
			}
		} else if (c == 0) {
			if (cur < 0) {
				ans++;
				can = m;
				cur = m;
			} else {
				can = min(can, cur);
			}
		}
	}
	return ans;
}
int main() {
	printf("%d\n", solve());
	return 0;

}
