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
int n;
void gao(int n) {
	if (n >= 5) printf("-O|"), n -= 5;
	else printf("O-|");
	rep(i, 0, n) putchar('O'); putchar('-');
	rep(i, n, 4) putchar('O'); puts("");
}
int main() {
	scanf("%d", &n);
	do {
		gao(n % 10);
		n /= 10;
	} while (n);
	return 0;
}
