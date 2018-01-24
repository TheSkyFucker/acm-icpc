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

double a, v, w, l, d;
const double eps = 1e-7;
///----------------------------------------------
bool ls(const double &a, const double &b) { return a + eps < b; }
void print(double ans) {printf("%.15f", ans); exit(0); }
///-----
int main() {

	///read
	cin >> a >> v;
	cin >> l >> d >> w;
	w = min(min(w, v), sqrt(2.0 * a * d));
	
	///prework
	if (ls(sqrt(2.0 * a * d), w)) {
		if (ls(sqrt(2.0 * a * l), v)) print(sqrt(2.0 * a * l) / a);
		print(v / a + (l - v * v / 2.0 / a) / v);
	}
	double ans2;
	if (ls(sqrt(2.0 * a * (l - d) + w * w), v)) {
		ans2 = (sqrt(2.0 * a * (l - d) + w * w) - w) / a;
	} else {
		ans2 = (v - w) / a + ((l - d) - (v * v - w * w) / 2.0 / a) / v;
	}

	///check
	//(1) : v` * v` - w * w = 2.0 * a * d2
	//(2) : v` * v`  = 2.0 * a * d1;
	//(1) + (2) : 2.0 * v` * v` - w * w = 2.0 * a * d
	if (ls(2.0 * v * v - w * w, 2.0 * a * d)) {
		double dmid = d - (2.0 * v * v - w * w) / 2.0 / a;
		double ans1 = (v + v - w) / a + dmid / v;
		print(ans1 + ans2);
	} else {
		double vmid = sqrt((2.0 * a * d + w * w) / 2.0);
		double ans1 = (vmid + vmid - w) / a;
		print(ans1 + ans2);
	}



}