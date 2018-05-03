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
const db eps = 1e-7;
int n,m,p1,p2;
db ans,l1,l2;
struct node{
	db x,y;	
	node() {}
	node(const db &x, const db &y) : x(x), y(y) { }
} a[N],b[N];

inline db Sqr(const db &d) { return d * d; }
inline double dis(node a,node b){ return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y)); }

inline node cal(const node &a, const node &b, const double &l){
	return node((b.x-a.x)*l + a.x, (b.y-a.y)*l + a.y);
}

double solve(const node &a1, const node &a2, const node &b1, const node &b2, const double &l){
	double lo=0,ro=l,mid1,mid2,w1,w2;
	rep(i,0,50) {
		mid1=(lo+lo+ro)/3;
		mid2=(ro+ro+lo)/3;
		w1=dis(cal(a1,a2, mid1 / l),cal(b1,b2, mid1 / l));
		w2=dis(cal(a1,a2, mid2 / l),cal(b1,b2, mid2 / l));
		if (w1>w2) lo=mid1;
		else  ro=mid2;
	}
	return w1;
}

int sgn(db d) { return (d > eps) - (d < -eps); }

int main() {
	scanf("%d",&n);
	ans=1<<30;
	rep(i,1,n+1) scanf("%lf%lf",&a[i].x,&a[i].y);
	scanf("%d",&m);
	rep(i,1,m+1) scanf("%lf%lf",&b[i].x,&b[i].y);
  p1=1;p2=1;
  while (p1<n&&p2<m) {
		l1=dis(a[p1],a[p1+1]);
		l2=dis(b[p2],b[p2+1]);
		if (l1>l2) {
				node tmp = cal(a[p1],a[p1+1], l2 / l1);
				ans=min(ans,solve(a[p1],tmp,b[p2],b[p2+1],l2));
				p2++;a[p1]=tmp;
				if (sgn(l1 - l2) == 0) p1++;
		}else {
				node tmp = cal(b[p2],b[p2+1], l1 / l2);
				ans=min(ans,solve(a[p1],a[p1+1],b[p2],tmp,l2));
				p1++;b[p2]=tmp;
				if (sgn(l1 - l2) == 0) p2++;
		}
  }
  printf("%.10f",ans);
	return 0;
}
