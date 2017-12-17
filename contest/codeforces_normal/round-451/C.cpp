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

int n;
void solve() {
    map<string, vector<string> > M;
    rep(i, 0, n) {
        string name; cin >> name;
        int m; scanf("%d", &m);
        rep(_m, 0, m) {
            string numb; cin >> numb; reverse(all(numb));
            M[name].pb(numb);
        }
    }
    printf("%d\n", sz(M));
    for (auto e : M){
        sort(all(e.se));
        vector<string> ans;
        rep(i, 0, sz(e.se)) {
            bool pass = false;
            rep(j, i + 1, sz(e.se)) {
                if (e.se[j].substr(0, sz(e.se[i])) == e.se[i]) {
                    pass = true;
                    break;
                }
            }
            reverse(all(e.se[i]));
            if (!pass) ans.pb(e.se[i]);
        }
        cout << e.fi << " " << sz(ans);
        rep(i, 0, sz(ans)) cout << " " << ans[i];
        cout << endl;
    }
}

int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf("%d", &n))solve();
    return 0;
}



