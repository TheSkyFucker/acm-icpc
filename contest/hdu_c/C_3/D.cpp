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
const int N = 1e5 + 7;
char str[N];
void solve() {
	scanf(" %s", str);
	int len = strlen(str);
	int ans = 0;
	rep(i, 0, len) if (str[i] >= '0' && str[i] <= '9') ans++;
	printf("%d\n", ans);
}
int main() {
	int tcase = 0 ;scanf("%d", &tcase);
	rep(icase, 0, tcase) solve();
	return 0;
}
