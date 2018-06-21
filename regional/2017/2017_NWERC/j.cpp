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
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string s; cin >> s;
	set<int> emp; emp.insert(-1); emp.insert(sz(s));
	rep(i, 0, sz(s)) if (s[i] == '0') emp.insert(i);
	rep(i, 0, sz(s)) if (s[i] == '2') {
		auto itr = emp.lower_bound(i), itl = itr; itl--;
		int pos = *itl + *itr - i;
		if (*itl >= 0) emp.erase(itl);
		if (*itr < sz(s)) emp.erase(itr);
		emp.insert(pos);
	}
	string ans(sz(s), '1');
	for (auto pos : emp) if (pos >= 0 && pos < sz(ans)) ans[pos] = '0';
	cout << ans;
	return 0;
}
