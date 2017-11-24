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
int main() {
	scanf("%d", &n);
	per(k, 1, 11) {
		int dig = ((1 << k) - 1) * (1 << (k - 1));
		if (n % dig == 0) { printf("%d\n", dig); break; }
	}
	return 0;

}
