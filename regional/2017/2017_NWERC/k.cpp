
 #include <bits/stdc++.h>
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
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << "\n"
#define endl "\n"

//-----
const int N=4500;
int data[N];
vector< pair<int,double> > V[N];
vector< pair<int,double> >solve(vector<pair<int,double> > a,vector<pair<int,double> >b)
{
	vector<pair<int,double> >ans;
	rep(i,0,sz(a))
	{
		pair<int,double> A=a[i];
		A.second=0;
		rep(j,0,sz(b))
			A.se += a[i].se * b[j].se * data[a[i].fi] / (data[a[i].fi] + data[b[j].fi]);
		ans.pb(A);
	}
	rep(i,0,sz(b))
	{
		pair<int,double> A=b[i];
		A.se = 0;
		rep(j,0,sz(a))A.se += b[i].se * a[j].se * data[b[i].fi] / (data[b[i].fi] + data[a[j].fi]);
		ans.pb(A);
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&data[i]);
	sort(data+2,data+n+1);
	int lo=1;
	while(lo<=n)lo<<=1;
	lo>>=1;
	int Index=0;
	rep(i,1,n-2*(n-lo)+1)V[i].pb(mp(++Index,1));
	rep(i,n-2*(n-lo)+1,lo+1)
	{
		++Index;
		V[i].pb(mp(Index,1.0*data[Index]/(data[Index]+data[Index+1])));
		++Index;
		V[i].pb(mp(Index,1.0*data[Index]/(data[Index]+data[Index-1])));
	}
	while(lo!=1)
	{
		rep(i,1,lo/2+1)V[i]=solve(V[i*2-1],V[i*2]);
		rep(i,lo/2+1,lo+1)V[i].clear();
		lo>>=1;
	}
	double ans=0;
	rep(i,0,sz(V[1]))if(V[1][i].first==1)ans=V[1][i].second;
	printf("%.10lf\n",ans);
	return 0;
}
