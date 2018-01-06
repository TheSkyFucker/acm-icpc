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
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
string name[N];
int n, score[N];
void solve() {
	map<string, int> bod;
	rep(i, 0, n) {
		cin >> name[i] >> score[i];
		bod[name[i]] += score[i];
	}
	set<string> winners;
	int mx = -INF; 
	for (auto e : bod) mx = max(mx, e.se);
	for (auto e : bod) if (e.se == mx) winners.insert(e.fi);
	bod.clear();
	rep(i, 0, n) { 
		if (winners.find(name[i]) == winners.end()) continue;
		if ((bod[name[i]] += score[i]) >= mx) {
			cout << name[i] << endl;
			return;
		}
	}
}
		
int main() {
	while (~scanf("%d", &n)) solve();

	return 0;
}
