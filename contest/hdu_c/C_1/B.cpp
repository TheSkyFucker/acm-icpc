#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<double, double> pii;
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
pii p1, p2;
db sqr(db d) { return d * d ;}
void solve() {
	printf("%.2f\n", sqrt(sqr(p1.fi - p2.fi), sqr(p1.s - p2.se)));
}
int main() {
	while (~scanf("%lf%lf%lf%lf", &p1.fi, &p1.se, &p2.fi, &p2.se)) solve();

	return 0;
}
