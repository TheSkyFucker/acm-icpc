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
int n, m, k;

int x = 1, y = 0, dy = 1;
pii nxt() {
	y += dy;
	if (y < 1 || y > m) dy *= -1, x++;
	y = max(1, min(y, m));
	return {x, y};
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 0, k) {
		int cnt = i == k - 1 ? n * m - 2 * (k - 1) : 2; 
		printf("%d", cnt);
		rep(j, 0, cnt) {
			auto p = nxt();
			printf(" %d %d", p.fi, p.se);
		}
		printf("\n");
	}
    
	return 0;
}
