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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string str; cin >> str;
	int cnto = 0, cnt_ = 0;
	rep(i, 0, sz(str)) {
		cnto += str[i] == 'o';
		cnt_ += str[i] == '-';
	}
	puts(!cnto || cnt_ % cnto == 0 ? "YES" : "NO");

	return 0;
}
