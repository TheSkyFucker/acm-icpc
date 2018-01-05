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
char str[N];
void solve() {
	int n = strlen(str);
	int ans= 0 ;
	rep(i, 0, n) if (str[i] == 'Q') 
		rep(j, i + 1, n) if (str[j] == 'A')
			rep(k, j + 1, n) if (str[k] == 'Q') ans++;
	printf("%d\n", ans);
}
int main() {
	while (~scanf(" %s", str)) solve();

	return 0;
}
