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
char str[N];
int main() {
    //freopen("xx.in", "r", stdin);
    set<string> room;
    int ans = 0;
    while (~scanf("%[^\n]", str)) {
        getchar();
        if (str[0] == '+') room.insert(str + 1);
        else if (str[0] == '-') room.erase(str + 1);
        else {
            int beg = 0; while (str[beg] != ':') beg++;
            ans += sz(room) * (strlen(str) - beg - 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}
