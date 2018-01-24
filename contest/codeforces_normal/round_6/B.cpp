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
const int N = 1e2 + 7;
int n, m;
char str[N][N], pc;
bool ans[N];
void solve() {
    rep(i, 0, n) scanf(" %s", str[i]);
    fill_n(ans, 26, 0);
    rep(i, 0, n) rep(j, 0, m) if (str[i][j] == pc) {
        static const int g[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        rep(k, 0, 4) {
            int ni = i + g[k][0]; if (ni < 0 || ni >= n) continue;
            int nj = j + g[k][1]; if (nj < 0 || nj >= m) continue;
            if (str[ni][nj] != '.' && str[ni][nj] != pc) ans[str[ni][nj] - 'A'] = true;
        }
    }
    int sum = 0;
    rep(i, 0, 26) sum += ans[i];
    printf("%d\n", sum);
}

int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf("%d%d %c", &n, &m, &pc)) solve();

    return 0;
}
