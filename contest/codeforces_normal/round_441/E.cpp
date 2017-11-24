#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;
///----------------------------------------------
int n, s1, s2, x[N];
bool solve(int lim) {
	int l = x[n - 1] - lim, r = x[n - 1] + lim;
	per(i, 0, n - 1) {
		int ll = x[i] - lim, rr = x[i] + lim;
		if (rr < l || ll > r) return false;
		if (x[i] < l || x[i] > r) l = max(ll, l), r = min(rr, r);
			else l = ll, r = rr;
	}
	return s1 >= l && s1 <= r || s2 >= l && s2 <= r;
}
int main() {
	
	//read
	scanf("%d%d%d", &n, &s1, &s2);
	rep(i, 0, n) scanf("%d", &x[i]);

	//work
	int ans = -1;
	for (int l = abs(s1 - s2), r = INF, mid = l + r >> 1; l <= r; mid = l + r >> 1)
		if (solve(mid)) r = (ans = mid) - 1; else l = mid + 1;
	printf("%d", ans);
	
	return 0;

}
