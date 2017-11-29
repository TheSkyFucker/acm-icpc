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
struct Digit {
	vi d;
	Digit() {}
	Digit(ll n, int b) {
		if (!n) { d.pb(0); return; }
		for (; n; n /= b) d.pb(n % b);
	}
	void out() {
		per(i, 0, sz(d)) printf("%c", d[i] <= 9 ? d[i] + '0' : d[i] - 10 + 'A');
	}
};

const int rom[30] = {
	3000,2000,1000,900,800,700,600,500,400,300,200,100,
	90,80,70,60,50,40,30,20,10,
	9,8,7,6,5,4,3,2,1
};
string smb[30]={
	"MMM","MM","M",
	"CM","DCCC","DCC","DC","D","CD","CCC","CC","C",
	"XC","LXXX","LXX","LX","L","XL","XXX","XX","X",
	"IX","VIII","VII","VI","V","IV","III","II","I"
};
string toRoman(ll d) {
	string r;
	rep(i, 0, 30) if (d >= rom[i]) d -= rom[i], r += smb[i];
	return r;
}

char str[5000];
ll read(int b) {
	scanf(" %s", str); int len = strlen(str);
	ll ret = 0; 
	rep(i, 0, len) {
		int d = str[i] - '0';
		if (d < 0 || d > 9) d += '0' - 'A' + 10;
		ret = ret * b + d;
	}
	return ret;
}

int a; char strb[100];
int getb() {
	int b = 0; rep(i, 0, strlen(strb)) b = b * 10 + strb[i] - '0'; return b;
}
void solve() {
	if (strb[0] != 'R') Digit(read(a), getb()).out();
	else printf("%s", toRoman(read(a)).c_str());
	puts("");
}

int main() {
	while (~scanf("%d %s", &a, strb)) solve();
	return 0;
}
