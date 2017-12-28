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
const int N = 1e2 + 7;
int y, m, d;
bool isleap(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }
const int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve() {
	//dd(y); dd(m); de(d);
	rep(i, 1, m) d += a[i];
	if (isleap(y) && m > 2) d++;
	printf("%d\n", d);
}
	
int main() {
	while (~scanf("%d/%d/%d\n", &y, &m, &d)) solve();

	return 0;
}
