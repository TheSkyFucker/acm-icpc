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

int qpow(int a, int b, int m) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = r * 1ll * a % m;
		a = a * 1ll * a % m;
	}
	return r;
}
int qpow(int a, int b) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = r * min(INT_MAX / r, a);
		a = a * min(INT_MAX / a, a);
	}
	return r;
}

int phi(int n) { 
	int r = n;
	for (int i = 2; i * i <= n; i++) if (n % i == 0) {
		r = r / i * (i  - 1);
		while (n % i == 0) n /= i;
	}
	if (n > 1) r = r / n * (n - 1); 
	return r;
}

ll dp[100];
int solve(int n, int m) {
	if (m == 1) return 0;
	int p = phi(m);
	if (n < 10 && dp[n - 1] <= p) {
	//	dd(n); dd(dp[n - 1]); de(m);
		return qpow(n, dp[n - 1], m);
	}
	return qpow(n, solve(n - 1, p) + p, m);
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	dp[0] = 1; rep(i, 1, 10) dp[i] = qpow(i, dp[i - 1]);
	printf("%d", solve(n, m));
	
	return 0;
}
