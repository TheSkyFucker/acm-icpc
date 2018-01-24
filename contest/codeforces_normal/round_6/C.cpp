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
const int N = 1e5 + 7;
int n, t[N];
void solve() {
     rep(i, 0, n) scanf("%d", t + i);
     int ta = 0, tota = 0;
     int tb = 0, totb = 0;
     while (tota + totb < n) {
        if (ta <= tb) {
            ta += t[tota++];
        }
        else {
            tb += t[n - 1 - (totb++)];
        }
     }
     printf("%d %d\n", tota, totb);
}
int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf("%d", &n)) solve();

    return 0;
}

