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

//-----
int l[4];
void solve(){
    rep(i, 1, 4) scanf("%d", l + i);
    sort(l, l + 4);
    int ans = 0;
    rep(a, 0, 4) rep(b, a + 1, 4) rep(c, b + 1, 4) {
        if (l[a] + l[b] > l[c]) ans = max(ans,  2);
        if (l[a] + l[b] == l[c]) ans = max(ans, 1);
    }
    puts(ans == 2 ? "TRIANGLE" : ans == 1 ? "SEGMENT" : "IMPOSSIBLE");
}
int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf("%d", l + 0)) solve();
    return 0;
}
