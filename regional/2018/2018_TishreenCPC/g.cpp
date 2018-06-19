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
#define de(x) cout << #x << " = " << x << "\n"
//-----

const int BSZ = 700, N = 1e5 + 7;
ll a[N], bs[N], bb[N], bd[N];
int bn, bl[N], br[N], sz[N];
void ini(int n) {
	bn = (n - 1) / BSZ + 1;
	rep(i, 0, n) a[i] = 0;
	rep(b, 0, bn) {
		bl[b] = b * BSZ;
		br[b] = min(n, (b + 1) * BSZ);
		sz[b] = br[b] - bl[b];
		bb[b] = bd[b] = bs[b] = 0;
	}
}
void bud(int b) {
	rep(i, bl[b], br[b])
		a[i] += bb[b] + (i - bl[b] + 1) * bd[b];
	bb[b] = bd[b] = 0;
}
void upd(int b, int l, int r) {
	int nl = max(l, bl[b]);
	int nr = min(r, br[b]);
	if (nl >= nr) return;
	if (nr - nl == sz[b]) {
		bb[b] += nl - l, bd[b]++;
		bs[b] += sz[b] * (sz[b] + 1) / 2 + sz[b] * (nl - l);
		return;
	}
	rep(i, nl, nr) a[i] += i - l + 1, bs[b] += i - l + 1;
}
ll qry(int b, int l, int r) {
	int nl = max(l, bl[b]);
	int nr = min(r, br[b]);
	if (nl >= nr) return 0;
	if (nr - nl == sz[b]) return bs[b];
	bud(b);
	ll ret = 0;
	rep(i, nl, nr) ret += a[i];
	return ret;
}
int qop[N], ql[N], qr[N], n = 1e5;
ll ans[N];
void solve() {
	int q; cin >> q;
	rep(i, 0, q) cin >> qop[i] >> ql[i] >> qr[i], ql[i]--, qr[i]--;
	fill_n(ans, q, 0);
	rep(_, 0, 2) {
		ini(n);
		rep(i, 0, q) {
			if (qop[i] == 1) rep(b, 0, bn) upd(b, ql[i], qr[i] + 1);
			else if (_ == 0) rep(b, 0, bn) ans[i] -= qry(b, 0, ql[i]);
			else rep(b, 0, bn) ans[i] += qry(b, ql[i], n);
			ql[i] = n - 1 - ql[i];
			qr[i] = n - 1 - qr[i];
			swap(ql[i], qr[i]);
		}
	}
	rep(i, 0, q) if (qop[i] == 2) cout << ans[i] << endl;
}	

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tcas; cin >> tcas;
	rep(cas, 0, tcas) solve();
	return 0;
}
