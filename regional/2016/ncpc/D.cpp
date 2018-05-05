
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
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----

int n,a[500];
ll num,ans;

int main() {
  scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);	
	ans=100;
	rep(i,2,n+1) {
		if (a[i]>a[i-1]) {
			num=min(100000ll,ans/a[i-1]);
			ans+=num*(a[i]-a[i-1]);
		}
	}
   printf("%lld",ans); 
	return 0;
}
