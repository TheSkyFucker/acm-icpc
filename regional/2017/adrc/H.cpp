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
const int N=100005<<2;
const double pi=acos(-1);

struct C {
	double r,i;
	C() {
		r=i=0;
	}
	C(double _r,double _i){
		r=_r,i=_i;
	}
	C operator+(const C &p) const{
		return C(r+p.r,i+p.i);
	}
	C operator*(const C &p) const{
		return C(r*p.r-i*p.i,r*p.i+i*p.r);
	}
	C operator-(const C &p) const{
		return C(r-p.r,i-p.i);
	}
};
inline C conj(const C &p)
{
	return C(p.r,-p.i);
}
C w[N],A[N],B[N],dfa[N],dfb[N],dfc[N],dfd[N];
int L,bitrev[N];
void init(int len){
	L=0;
	while(1<<L<=len)++L;
	int n=1<<L;
	rep(i,0,n)
		bitrev[i]=(bitrev[i>>1]>>1)|((i&1)<<(L-1));
	rep(i,0,n)
		w[i]=C(cos(2*pi*i/n),sin(2*pi*i/n));
}
void fft(C a[],const int &n){
	rep(i,0,n)
		if(i<bitrev[i])
			swap(a[i],a[bitrev[i]]);
	for(int i=2,d=n>>1;i<=n;i<<=1,d>>=1)
		for(int j=0;j<n;j+=i){
			C *l=a+j,*r=a+j+(i>>1),*p=w;
			for(int k=0;k<(i>>1);++k){
				C tmp=(*r)*(*p);
				*r=*l-tmp,*l=*l+tmp;
				++l,++r,p+=d;
			}
		}
}
vector<int> gao(vector<int> &a,vector<int> &b)
{
	init(sz(a)+sz(b));
	int n=1<<L;
	rep(i,0,n)A[i]=B[i]=C(0,0);
	rep(i,0,sz(a))A[i]=C(a[i]&32767,a[i]>>15);
	rep(i,0,sz(b))B[i]=C(b[i]&32767,b[i]>>15);
	fft(A,n),fft(B,n);
	rep(i,0,n){
		int j=(n-i)&(n-1);
		static C da,db,dc,dd;
		da=(A[i]+conj(A[j]))*C(0.5,0);
		db=(A[i]-conj(A[j]))*C(0,-0.5);
		dc=(B[i]+conj(B[j]))*C(0.5,0);
		dd=(B[i]-conj(B[j]))*C(0,-0.5);
		dfa[j]=da*dc,dfb[j]=da*dd;
		dfc[j]=db*dc,dfd[j]=db*dd;
	}
	rep(i,0,n){
		A[i]=dfa[i]+dfb[i]*C(0,1);
		B[i]=dfc[i]+dfd[i]*C(0,1);
	}
	fft(A,n),fft(B,n);
	vector<int> ret(n,0);
	rep(i,0,n){
		ll da=(ll)(A[i].r/n+0.5);
		ll db=(ll)(A[i].i/n+0.5);
		ll dc=(ll)(B[i].r/n+0.5);
		ll dd=(ll)(B[i].i/n+0.5);
		ret[i]+=(da+((db+dc)<<15)+(dd<<30));
	}
	return ret;
}
/*void strrev(char *a)
{
	int n=strlen(a);
	rep(i,0,n/2+1)swap(a[i],a[n-i-1]);
}*/
char jug[N],my[N];
char a[]="SPR",b[]="RSP";
int res[N];
vector<int> V1,V2,RES;
int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  scanf("%s%s",jug,my);
  strrev(jug);
  int njug=strlen(jug),nmy=strlen(my);
  rep(cas,0,3)
  {
  	V1.clear();V2.clear();
  	rep(i,0,njug)V1.pb(jug[i]==a[cas]);
		rep(i,0,nmy)V2.pb(my[i]==b[cas]);
		RES=gao(V1,V2);
		rep(i,0,sz(RES))res[i]+=RES[i];
	}
	int ans=0;
	rep(i,0,njug)ans=max(ans,res[i]);
	printf("%d\n",ans);
	return 0;
}
