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
const int N = 1e3 + 7;
int n;
char str[N][N];
int main() {
    //freopen("xx.in", "r", stdin);
    int mx = 0;
    while (~scanf("%[^\n]", str[n])) {
        getchar();
        int len = strlen(str[n++]);
        mx = max(mx, len);
    }
    rep(i, 0, mx + 2) putchar('*');
        puts("");
    char tp = 'l';
    rep(i, 0, n) {
        putchar('*');
        int emp = mx - strlen(str[i]);
        int empl = emp >> 1;
        int empr = emp >> 1;
        if (empl + empr < emp) {
            if (tp == 'l') empr++;
            else empl++;
            tp = tp == 'l' ? 'r' : 'l';
        }
        rep(j, 0, empl) putchar(' ');
        printf("%s", str[i]);
        rep(j, 0, empr) putchar(' ');
        putchar('*');
        puts("");
    }
    rep(i, 0, mx + 2) putchar('*');
    return 0;
}
