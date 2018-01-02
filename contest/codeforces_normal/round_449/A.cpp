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

//------
const int N = 1e2 + 7;
int n, m;
char str[N];
void solve() {
	scanf(" %s", str + 1);
	rep(_m, 0, m) {
		int l, r; char c1, c2;
		scanf("%d%d %c %c", &l, &r, &c1, &c2);
		rep(i, l, r + 1) if (str[i] == c1) str[i] = c2;
	}
	puts(str + 1);
}
int main() {
	while (~scanf("%d%d", &n, &m)) solve();

	return 0;
}
