#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
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
int n;
bool ok(int d) {
	if (d < 0) return false;
	int ret = d;
	for (; d; d/=10) ret+=d%10;
	return ret == n;
}
int main() {
	
	scanf("%d", &n);
	vi ans;
	rep(i, 0, 200) if (ok(n - i)) ans.pb(n - i);
	printf("%d\n", sz(ans)); 
	per(i, 0, sz(ans)) printf("%d%c", ans[i], " \n"[i == 0]);

	
	return 0;
}
