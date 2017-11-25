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
const int N = 1e7 + 6;
int n;

int pri[N], ntp[N], low[N], phi[N], pn;
void getpri() {
	phi[1] = 1; ntp[1] = 1; low[1] = 1;
	rep(i, 2, N) {
		if (!ntp[i]) pri[pn++] = i, phi[i] = i - 1, low[i] = i;
		for (int j = 0, o; j < pn && (o = pri[j] * i) < N; j++) {
			ntp[o] = 1;
			low[o] = pri[j];
			if (i % pri[j]) phi[o] = (pri[j] - 1) * phi[i]; 
			else { phi[o] = pri[j] * phi[i]; break; }
				
		}
	}
}

ll gao_tp1() {
	ll ret = 0, tmp = 1;
	rep(i, 2, n + 1) {
		if (!ntp[i]) { tmp++; ret += (n / i) - 1; }
		else ret += phi[i] - tmp;
	}
	return ret;
}

int cnt[N];
ll gao_tp2() {
	ll ret = 0, tmp = 0, _tmp = n;
	rep(i, 2, n + 1) if (ntp[i] || i * 2 <= n) cnt[low[i]]++, tmp++;
	rep(i, 2, n + 1) {
		while (i * _tmp > n) tmp -= cnt[_tmp--];
		if (!ntp[i]) {
			ret += tmp;
			for (int j = i; j <= n; j += i) if (1ll * low[j] * i <= n) ret--;
		}
	}
	return ret;
}

ll gao_tp3() {
	ll ret = 0, tmp = 0, _tmp = n;
	rep(i, 2, n + 1) if (!ntp[i]) tmp++;
	rep(i, 2, n + 1) {
		if (!ntp[i]) tmp--;
		while (_tmp > i && i * _tmp > n) tmp -= !ntp[_tmp--];
		if (_tmp == i) return ret;
		if (!ntp[i]) ret += tmp;
	}
	return ret;
}

int main() {
	getpri();
	scanf("%d", &n);
	ll ans = 0; int bad = 1;
	rep(i, 2, n + 1) {
		if (!ntp[i] && i * 2 > n) { bad++; continue; }
		ans += i - 1 - phi[i] + (phi[i] - bad) * 3;
	}
//	int cut = 0;
//	rep(i, 2, n + 1) rep(j, i + 1, n + 1) if (__gcd(i, j) == 1 && low[i] * low[j] <= n) cut++;
	
	ll tp1 = gao_tp1(); //de(tp1);
	ll tp2 = gao_tp2(); //de(tp2);
	ll tp3 = gao_tp3(); //de(tp3);
//	assert(cut == tp1 + tp2 - tp3);
	printf("%lld", ans - (tp1 + tp2 - tp3));

	return 0;
}
