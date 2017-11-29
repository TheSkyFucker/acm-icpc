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
int n, k;
void solve() {
	int sum = 0, sig = 0;
	rep(i, 0, k) {
		int a; scanf("%d", &a);
		if (a & 1) a++, sig++;
		sum += a;
	}
	puts(sum > 8 * n || (sum == 8 * n && sig < n && k == 4 * n) ? "NO" : "YES");
}
int main() {
	while (~scanf("%d%d", &n, &k)) solve();
	return 0;
}


	
			
