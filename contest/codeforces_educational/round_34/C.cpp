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
const int N = 5e3 + 7;
int n, a[N];
void solve() {
    rep(i, 0, n) scanf("%d", &a[i]);
    sort(a, a + n);
    int ans = 1;
    for (int l = 0, r; l < n; l = r) {
        r = l; while (r < n && a[r] == a[l]) r++;
        ans = max(ans, r - l);
    }
    printf("%d\n", ans);
}
int main() {
    while (~scanf("%d", &n)) solve();
}

