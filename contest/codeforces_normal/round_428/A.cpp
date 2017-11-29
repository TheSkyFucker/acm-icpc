#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define de(x) cout << #x << " => " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

///----------------------------------------------

int main() {

	///read
	int n, k; cin >> n >> k;
	int has = 0;
	rep(i, 0, n) {
		int dig; scanf("%d", &dig);
		has += dig;
		k -= min(8, has);
		has -= min(8, has);
		if (k <= 0) { printf("%d", i + 1); return 0; }
	}
	printf("-1");



}
