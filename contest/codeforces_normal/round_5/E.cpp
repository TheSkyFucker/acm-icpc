#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define de(x) cout << #x << " => " << x << endl
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
typedef pair<int, int> pii;

#define pb push_back
typedef vector<int> vi;

const int N = 1e6 + 7;
///---------------------
int dig[N], tmp[N], n;
int getmx(int l, int r) { int mx = l; rep(i, l, r) if (dig[i] > dig[mx]) mx = i; return mx; }
///---------------------
ll gao() {
    ll ret = 0;
    vector<pii> vu; vu.pb(mp(dig[0], 1));
    rep(i, 1, n) {
        while (dig[i] > vu.back().fi) {
            ret += vu.back().se;
            vu.pop_back();
        }
        if (dig[i] < vu.back().fi) {
            vu.pb(mp(dig[i], 1)); ret++; 
            continue;
        }
        ret += vu.back().se + (sz(vu) > 1);
        vu.back().se++;
    }
    if (vu[0].se > 1 && sz(vu) > 1) ret += vu[1].se;
    rep(i, 2, sz(vu)) ret += vu[i].se;
    return ret;
}   
//----
int main() {
    
    ///read
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", &dig[i]);
    int mx = getmx(0, n);
    rep(i, 0, n) tmp[i] = dig[(mx + i) % n];
    rep(i, 0, n) dig[i] = tmp[i];
    
    ///work
    cout << gao() << endl;

    return 0;
}