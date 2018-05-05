
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

const int N=100005;
char s[N];
int a[30],n,x,w,r;


int main() {
	scanf("%s",s);
	n=strlen(s);r=25;
	rep(i,21,26) a[i]=2;
	rep(i,16,21) a[i]=3;
	rep(i,11,16) a[i]=4;
	rep(i,1,11) a[i]=5;
	rep(i,0,n) {
		if (s[i]=='W') {
			w++;if (w>=3 && r>=6) x+=2;else x+=1;
			if (x>a[r]) {x-=a[r];r--;}
		}	else {
			w=0;	
			if (r<20 || (r==20 && x>0)) {
					x--;if(x<0) {r++;x=a[r]-1;}
			}
		}
		if (r==0) break;
	}
  if (r==0) printf("Legend");else printf("%d",r);
	return 0;
}
