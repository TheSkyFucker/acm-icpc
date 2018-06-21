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
const int N=505;
int M[N];
int d[N],s[N];
struct app
{
	int endline,time,id;
	app(){}
	app(int _endline,int _time,int _id){endline=_endline;time=_time;id=_id;}
};
vector<app> V;
vector<int> VV;
int cmp(app a,app b)
{
	return a.endline<b.endline;
}
int cmp1(int a,int b)
{
	return M[a]<M[b];
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,c;
	scanf("%d%d",&n,&c);
	rep(i,0,n)scanf("%d%d",&d[i],&s[i]);
	rep(i,0,n)
	{
		if(d[i]>s[i])V.pb(app(c-d[i]+s[i],s[i],i+1));
		else V.pb(app(c,s[i],i+1));
	}
	sort(all(V),cmp);
	priority_queue<pii> Q;
	int T=0;
	rep(i,0,n)
	{
		if(V[i].endline<0)continue;
		T+=V[i].time;
		M[V[i].id]=i;
		Q.push(mp(V[i].time,V[i].id));
		while(T>V[i].endline)
		{
			pii f=Q.top();Q.pop();
			T-=f.first;
		}
	}
	printf("%d\n",sz(Q));
	while(!Q.empty())
	{
		pii f=Q.top();Q.pop();
		VV.pb(f.second);
	}
	sort(all(VV),cmp1);
	rep(i,0,sz(VV))printf("%d%c",VV[i],i==sz(VV)-1?'\n':' ');
	return 0;
}
