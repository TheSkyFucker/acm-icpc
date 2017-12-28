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

//------
int score;
char getlv(int d) {
	if (d < 0 || d > 100) return '$';
	rep(i, 1, 5) if (score >= 100 - i * 10) return 'A' + i - 1;
	return 'E';
}
void solve() {
	char lv = getlv(score);
	if (lv == '$') puts("Score is error!");
	else printf("%c\n", lv);
}
int main() {
	while (~scanf("%d", &score)) solve();

	return 0;
}
