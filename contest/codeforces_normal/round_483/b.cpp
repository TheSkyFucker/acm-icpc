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
const int N = 1e2 + 7;
int n;
pair<int, string> str[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> str[i].se, str[i].fi = sz(str[i].se);
	sort(str, str + n);
	rep(i, 1, n) if (!~str[i].se.find(str[i - 1].se)) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	rep(i, 0, n) cout << str[i].se << endl;

	return 0;
}
