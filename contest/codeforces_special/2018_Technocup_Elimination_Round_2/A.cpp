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
int n, m, a, b, v[10];
void solve() {
	int mia = 10; rep(i, 0, n) scanf("%d", &a), mia = min(mia, a), v[a]++;
	int mib = 10; rep(i, 0, m) scanf("%d", &b), mib = min(mib, b), v[b]++;
	rep(i, 1, 10) if (v[i] > 1) { printf("%d\n", i); return; }
	printf("%d\n", min(mia, mib) * 10 + max(mia, mib));
}
int main() {
	while (~scanf("%d%d", &n, &m)) solve();
	return 0;
}
