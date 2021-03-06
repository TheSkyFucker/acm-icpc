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
const int N = 2e5 + 7;
int a[N], n, m, k;
void solve() {
    rep(i, 0, n) scanf("%d", &a[i]);
    sort(a, a + n);
    queue<int> que;
    int ans = 0;
    rep(i, 0, n) {
        while (!que.empty() && a[i] - que.front() + 1 > m) que.pop();
        if (sz(que) + 1 == k) ans++;
        else que.push(a[i]);
    }
    printf("%d\n", ans);
}
int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf("%d%d%d", &n, &m, &k)) solve();
    return 0;
}
