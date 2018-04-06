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
void gao1() {
	int _ = 1;
	rep(i, 0, n - 6) printf("%d %d\n", _, _ + 1), _++;
	rep(i, 0, 3) printf("%d %d\n", _, _ + i + 1);
	rep(i, 0, 2) printf("%d %d\n", _ + 1, _ + 3 + i + 1);
}
int main() {
	scanf("%d", &n);
	if (n >= 6) gao1(); else puts("-1");
	rep(i, 1, n) printf("%d %d\n", i, i + 1);
    
	return 0;
}
