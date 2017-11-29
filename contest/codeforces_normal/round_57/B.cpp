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

bool ign(char c) { return c == '-' || c == ';' || c == '_'; }
char str[N];
string read() {
	scanf(" %s", str); int len = strlen(str);
	string r; rep(i, 0, len) if (!ign(str[i])) r += str[i];
	rep(i, 0, sz(r)) if (r[i] >= 'a' && r[i] <= 'z') r[i] = r[i] - 'a' + 'A';
	return r;
}

string sou[3];
void solve() {
	rep(i, 0, 3) sou[i] = read();
	int m; scanf("%d", &m);
	rep(i, 0, m) {
		string tmp = read();
//		de(tmp);
		int pe[3] = {0, 1, 2};
		bool ok = false;
		do {
			string ddd; rep(i, 0, 3) ddd += sou[pe[i]];
			if (ddd == tmp) { ok = true; break; }
		} while (next_permutation(pe, pe + 3));
		puts(ok ? "ACC" : "WA");
	}
}

int main() {
	solve();
	return 0;
}
