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
int n; char str[N];
int solve() {
	scanf(" %s", str + 1);
	map<int, int> M; M[0] = 0;
	int sum = 0;
	int ret = 0;
	rep(i, 1, n + 1) {
		sum += (str[i] == '1') - (str[i] == '0');
		if (M.count(sum)) ret = max(ret, i - M[sum]);
		else M[sum] = i;
	}
	return ret;
}

int main() {
	while (~scanf("%d", &n)) printf("%d\n", solve());
	return 0;
}
