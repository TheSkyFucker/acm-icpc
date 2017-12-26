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
const int N = 30;
const int m[2][24] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int n, a[N];
void solve() {
	rep(i, 0, n) scanf("%d", &a[i]);
	rep(i, 0, 2) {
		rep(j, 0, 24) {
			bool ok = true;
			rep(k, 0, n) if (a[k] != m[i][(j + k) % 24]) { ok = false; break; }
			if (ok) { puts("Yes"); return; }
		}
	}
	puts("No");
}

int main() {
	while (~scanf("%d", &n)) solve();

	return 0;
}


