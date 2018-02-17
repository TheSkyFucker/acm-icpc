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

int mul(int a, int b, const int &M) { return 1ll * a * b % M; }
int add(int a, int b, const int &M) { if ((a += b) >= M) a -= M; return a; }
namespace HH {
    const int N = 1e4 + 7, HN = 2;
    const int B[2] = {29123, 38734667};
    const int P[2] = {1000000007, 1000000009};
    int pw[HN][N];
    void pre() {
        rep(i, 0, HN) {
            pw[i][0] = 1;
            rep(j, 1, N) pw[i][j] = mul(pw[i][j - 1], B[i], P[i]);
        }
    }
    int val(char ch) { return ch; }
    struct Hash {
        int h[HN][N], sz;
        void ini(string s) {
            sz = sz(s); 
            rep(i, 0, HN) {
                h[i][0] = val(s[0]);
                rep(j, 1, sz) h[i][j] = add(val(s[j]), mul(h[i][j - 1], B[i], P[i]), P[i]);
            }
        }
        int geth(int l, int r, int k = 0) {
            return add(r > 0 ? h[k][r - 1] : 0, P[k] - mul(l > 0 ? h[k][l - 1] : 0, pw[k][r - l], P[k]), P[k]);
        }
    };
}

const int N = 2e3 + 7;

int tp[200], s[N];
int main() {
  using namespace HH;
  pre();
  string str; cin >> str;
  Hash h; h.ini(str);
	rep(i, 0, 26) {
		char ch; scanf(" %c", &ch);
		tp[i] = ch == '0';
	}
  int k; scanf("%d", &k);
	rep(i, 0, sz(str)) s[i] = tp[str[i] - 'a'];
	//rep(i, 0, sz(str)) de(s[i]);
	rep(i, 1, sz(str)) s[i] += s[i - 1];
	set<pii> Set;
	rep(l, 1, sz(str) + 1) {
		rep(i, 0, sz(str) + 1 - l) {
			pii hv = {h.geth(i, i + l, 0), h.geth(i, i + l, 1)};
			if (s[i + l - 1] - (i ? s[i - 1] : 0) <= k) {
				if (Set.find(hv) == Set.end()) {
					Set.insert(hv);
					/*dd(i); de(i + l - 1);
					de(s[i + l - 1] - (i ? s[i - 1] : 0));*/
				}
			}
		}
	}
	printf("%d\n", sz(Set));
	return 0;
}
