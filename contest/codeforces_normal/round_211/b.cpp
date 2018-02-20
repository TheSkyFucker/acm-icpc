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
const int N = 2e5 + 7;
int n, k, a[N];
int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n + 1) scanf("%d", a + i), a[i] += a[i - 1];
	pii ans = {pw(30), 0};
	rep(i, 1, n + 1 + 1 - k) {
		ans = min(ans, {a[i + k - 1] - a[i - 1], i});
	}
	printf("%d\n", ans.se);



		
    
	return 0;
}
