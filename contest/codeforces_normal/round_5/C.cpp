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
const int N = 1e6 + 7;
char str[N];
int n;
void solve() {
    n = strlen(str);
    int tmp = 0, pre = -1;
    int mx = 0, cnt = 1;
    stack<int> stk; stk.push(-1);
    rep(i, 0, n) {
        if (str[i] == '(') stk.push(i);
        else {
            if (sz(stk) == 1) {
                stk.pop();
                stk.push(i);
                continue;
            }
            stk.pop();
            if (mx < i - stk.top()) {
                mx = i - stk.top();
                cnt = 1;
            }
            else if (mx == i - stk.top()) {
                cnt++;
            }
        }
    }
    printf("%d %d\n", mx, cnt);
}

int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf(" %s", str)) solve();

    return 0;
}
