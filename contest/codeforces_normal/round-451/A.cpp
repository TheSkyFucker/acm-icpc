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
    if (n % 10 <= 5) n -= n % 10;
    else n += 10 - (n % 10);
    printf("%d\n", n);
}

int main() {
    //freopen("xx.in", "r", stdin);
    while (~scanf("%d", &n)) solve();
    return 0;
}
