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
const int N = pw(8);
int n, k;
int col[N], sz[N];
void gao(int ai) {
	int mi = ai;
	rep(j, 0, k) if (ai - j < 0 || ~col[ai - j]) break; else mi = ai - j;
	sz[ai] = ai + 1 - mi;
	if (mi - 1 >= 0 && ~col[mi - 1] && sz[ai] + sz[mi - 1] <= k) {
		sz[ai] += sz[mi - 1];
		rep(j, mi, ai + 1) col[j] = col[mi - 1];
	}
	else rep(j, mi, ai + 1) col[j] = mi;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> k;
	fill_n(col, N, -1);
	rep(i, 0, n) {
		int ai; cin >> ai;
		if (!~col[ai]) gao(ai);
		if (i) cout << ' ';
		cout << col[ai];
	}

	return 0;
}
