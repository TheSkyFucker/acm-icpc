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
const int N = 1e5 + 7;
int n;

int solve() {
	scanf("%d", &n);
	int ret = n / 4;
	if (n % 4 == 0) return n / 4;
	if (n % 4 == 1) return n >= 9 ? n / 4 - 1 : -1;
	if (n % 4 == 2) return n >= 6 ? n / 4 - 0 : -1;
	if (n % 4 == 3) return n >= 15 ? n / 4 - 1 : -1;
}
	

int main() {
	int tcase = 0; scanf("%d", &tcase);
	rep(icase, 0, tcase) printf("%d\n", solve());
	return 0;
}
