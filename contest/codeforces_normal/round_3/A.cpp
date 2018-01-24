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
const int N = 1e2 + 6;
char ch1, ch2;
int sx, sy, tx, ty;
int Abs(int d) { return d > 0 ? d : - d; }
void solve() {
	sx = ch1 - 'a';
	sy = ch2 - '1';
	scanf(" %c%c", &ch1, &ch2);
	tx = ch1 - 'a';
	ty = ch2 - '1';
	int dia = min(Abs(sx - tx), Abs(sy - ty));
	printf("%d\n", Abs(sx - tx) + Abs(sy - ty) - dia);
	char dir[3]; dir[2] = '\0';
	dir[0] = sx < tx ? 'R' : 'L';
	sx += sx < tx ? dia : -dia;
	dir[1] = sy < ty ? 'U' : 'D';
	sy += sy < ty ? dia : -dia; 
	rep(i, 0, dia) puts(dir);
	if (sx == tx) rep(i, 0, Abs(sy - ty)) puts(sy < ty ? "U" : "D");
	if (sy == ty) rep(i, 0, Abs(sx - tx)) puts(sx < tx ? "R" : "L");
}

int main() {
	while (~scanf(" %c%c", &ch1, &ch2)) solve();
	return 0;
}