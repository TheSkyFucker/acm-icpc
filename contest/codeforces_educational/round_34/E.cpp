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
const int N = 5e3 + 8;
int n, m;
string str[N];

vi ckp[N];
bool get_ckp() {
	rep(i, 1, n) {
		ckp[i].clear();
		rep(j, 0, m) if (str[0][j] != str[i][j]) {
			ckp[i].pb(j);
			if (sz(ckp[i]) > 4) return false;
		}
	}
	return true;
}

bool can_same;
bool ck(int exp0, int exp1) {
	int exp[2] = {exp0, exp1};
	rep(i, 1, n) {
		vi dif;
		int cnt = 0;
		rep(j, 0, 2) {
			int pos = lower_bound(all(ckp[i]), exp[j]) - ckp[i].begin();
			if (pos == sz(ckp[i]) || ckp[i][pos] != exp[j])
				cnt |= 1 << j;
		}
		rep(j, 0, 2) if (cnt >> j & 1) ckp[i].pb(exp[j]);
		for (auto j : ckp[i]) if (str[i][j] != str[0][j]) {
			dif.pb(j); if (sz(dif) > 2) break;
		}
		rep(j, 0, 2) if (cnt >> j & 1) ckp[i].pop_back();
		if (sz(dif) > 2 || sz(dif) == 1) return false;
		if (sz(dif) == 0 && can_same == false) return false;
	}
	return true;
}
			
int cnt[30];
void solve() {
	rep(i, 0, n) cin >> str[i];
	fill_n(cnt, 26, 0);
	rep(i, 0, m) cnt[str[0][i] - 'a']++;
	can_same = false;
	rep(i, 0, 26) if (cnt[i] > 1) can_same = true;
	rep(i, 0, n) {
		int tmp[26];
		fill_n(tmp, 26, 0);
		rep(j, 0, m) tmp[str[i][j] - 'a']++;
		rep(j, 0, 26) if (tmp[j] != cnt[j]) {
			puts("-1");
			return;
		}
	}
	if (!get_ckp()) {
		puts("-1");
		return;
	}
	if (can_same && ck(0, 1)) {
		cout << str[0] << endl;
		return;
	}
	rep(i, 0, m) rep(j, i + 1, m) if (str[0][i] != str[0][j]) {
		swap(str[0][i], str[0][j]);
		if (ck(i, j)) {
			cout << str[0] << endl;
			return ;
		}
		swap(str[0][i], str[0][j]);
	}
	puts("-1");
}

int main() {
	while (~scanf("%d%d", &n, &m)) solve();

	return 0;
}