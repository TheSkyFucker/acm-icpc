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
string str;
char tmp[N];
void solve() {
	cin >> str;
	int pl = 0; while (str[pl] >= 'A' && str[pl] <= 'Z') pl++;
	int pr = sz(str) - 1; while (str[pr] >= '0' && str[pr] <= '9') pr--;
	if (pl == pr + 1) {
		int col = 0; rep(i, 0, pl) col = col * 26 + str[i] - 'A' + 1;
		int row = 0; rep(i, pr + 1, sz(str)) row = row * 10 + str[i] - '0';
		printf("R%dC%d\n", row, col);
	}
	else {
		int pc = 0; while (str[pc] != 'C') pc++;
		int row = 0; rep(i, 1, pc) row = row * 10 + str[i] - '0';
		int col = 0; rep(i, pc + 1, sz(str)) col = col * 10 + str[i] - '0';
		string scol; while (col) { scol += 'A' - 1 + (col - 1) % 26 + 1; col = (col - 1) / 26; }
		reverse(all(scol));
		cout << scol << row << endl;
	}
}

int main() {
	int tcase = 0; scanf("%d", &tcase);
	rep(icase, 0, tcase) solve();

	return 0;
}
