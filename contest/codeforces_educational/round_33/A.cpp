#include<bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for (int i=(a); i<(b); i++)
#define per(i,a,b) for (int i=(b-1); i>=(a); i--)
#define debug(x) cout << #x << " => " << x << endl
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;

#define pb push_back
typedef vector<int> vi;

typedef long long ll;
typedef long double ld;

///----------------------------------------------
int n;
bool solve() {
	scanf("%d", &n);
	int p1 = 1, p2 = 2;
	rep(i, 1, n + 1) {
		int w; scanf("%d", &w);
		int p3 = 6 - p1 - p2;
		if (w == p3) return false;
		if (w == p1) p2 = p3;
		else p1 = p3;
	}
	return true;
}
int main() {
	puts(solve() ? "YES" : "NO");
	return 0;

}
