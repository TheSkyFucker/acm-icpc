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
const int N = 1e5 + 7;
const ll LLINF = (ll)1e18 + 7;
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string fi_l = "What are you doing while sending \"";
string fi_m = "\"? Are you busy? Will you send \"";
string fi_r = "\"?";
ll l[N];
char get(int n, ll k) {
	if (n == 0) return k <= sz(f0) ? f0[k - 1] : '.';
	if (k <= sz(fi_l)) return fi_l[k - 1];
	else k -= sz(fi_l);
	if (k <= l[n - 1]) return get(n - 1, k);
	else k -= l[n - 1];
	if (k <= sz(fi_m)) return fi_m[k - 1];
	else k -= sz(fi_m);
	if (k <= l[n - 1]) return get(n - 1, k);
	else k -= l[n - 1];
	if (k <= sz(fi_r)) return fi_r[k - 1];
	else return '.';
}
int main() {
	string tmp = "What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";
	//de(sz(tmp));
	l[0] = sz(f0);
	rep(i, 1, N) l[i] = min(LLINF, sz(fi_l) + sz(fi_m) + sz(fi_r) + 2 * l[i - 1]);
	//rep(i, 0, 10) de(l[i]);
	int tcase; scanf("%d", &tcase);
	rep(icase, 0, tcase) {
		int n; ll k; scanf("%d%lld", &n, &k);
		printf("%c", get(n, k));
	}
	return 0;
}
