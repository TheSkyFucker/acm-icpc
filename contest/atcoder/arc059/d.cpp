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
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << "\n"
#define endl "\n"
 
//-----
vi v[30];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string s; cin >> s;
	rep(l, 1, 3) {
		rep(i, 0, sz(s) - l) if (s[i] == s[i + l]) {
			cout << i + 1 << " " << i + 1 + l;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}
