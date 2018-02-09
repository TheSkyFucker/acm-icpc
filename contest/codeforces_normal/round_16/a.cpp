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
int n, m;
char s[1000];
int main() {
	scanf("%d%d", &n, &m);
	bool ans = true;
	char p = '#';
	rep(i, 0, n) {
		scanf(" %s", s);
		rep(i, 1, m) if (s[i] != s[i - 1]) ans = false;
		if (s[0] == p) ans = false;
		p = s[0];
	}
  puts(ans ? "YES" : "NO"); 
	return 0;
}
