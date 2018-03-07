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
int a[10][10], b[10];
int gao() {
	int ret = 0;
	rep(i, 0, 4) {
		ret += (a[b[i]][b[i + 1]] + a[b[i + 1]][b[i]]) * (i / 2 + 1);
	}
	return ret;
}

int main() {
	rep(i, 0, 5) rep(j, 0, 5) scanf("%d", &a[i][j]);
	rep(i, 0, 5) b[i] = i;
	int ans = 0;
	do {
		ans = max(ans, gao());
	} while (next_permutation(b, b + 5));
	printf("%d", ans);
    
	return 0;
}
