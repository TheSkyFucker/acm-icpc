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
//const db PI = acos(-1.);
#define PI 3.1415927
db r;
db v(db r) { return 4. / 3 * PI * r * r * r; }
void solve() {
	printf("%.3f\n", v(r));
}
int main() {
	while (~scanf("%lf", &r)) solve();

	return 0;
}
