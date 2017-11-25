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
//#define local
const int N = 5e3 + 7;
int b[N], p[N], n;

struct Mac {
	int p[N], b[N];
	void ini() {
		vi v; v.resize(n); rep(i, 0, n) v[i] = i;
		rep(i, 0, n) {
			int pos = rand() % sz(v);
			p[i] = v[pos];
			swap(v[pos], v.back()); v.pop_back();
			b[p[i]] = i;
		}
		printf("P[]: "); rep(i, 0, n) printf("%d%c", p[i], " \n"[i == n - 1]);
		printf("B[]: "); rep(i, 0, n) printf("%d%c", b[i], " \n"[i == n - 1]);
	}
	int ask(int i, int j) {
		return p[i] ^ b[j];
	}
}	mac;

int ask(int a, int b) {
	printf("? %d %d\n", a, b); fflush(stdout);
	int ret; 
#ifndef local
	scanf("%d", &ret);
#else
	ret = mac.ask(a, b);
	//printf("%d\n", ret);
#endif
	return ret;
}

int _b[N], _p[N];
bool gao() {
	rep(i, 0, n) _b[i] = b[i], _p[i] = p[i];
	rep(i, 0, n) _b[i] ^= _p[0];
	rep(i, 1, n) _p[i] ^= _b[0];
	rep(i, 0, n) if (_b[_p[i]] != i) return false;
	return true;
}

int main() {
#ifndef local
	scanf("%d", &n);
#else
	srand((unsigned)time(0));
	n = 10;
	mac.ini();
#endif
	rep(i, 0, n) b[i] = ask(0, i);
	rep(i, 1, n) p[i] = ask(i, 0);
	int ans = 0, tmp = -1;
	for (p[0] = 0; p[0] < n; p[0]++) if (gao()) ans++, tmp = p[0];
	printf("!\n%d\n", ans);
	p[0] = tmp; gao(); 
	rep(i, 0, n) printf("%d%c", _p[i], " \n"[i == n - 1]);
	return 0;
}
