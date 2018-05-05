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
template<class T>
struct dinic
{
	const static int N=105,M=505*10;
	int s,t,n,h[N],cur[N],level[N],q[N],e,ne[M],to[M];
	T cap[M],flow;
	void liu(int u,int v,T w){to[e]=v;ne[e]=h[u];cap[e]=w;h[u]=e++;}
	void link(int u,int v,T w){liu(u,v,w);liu(v,u,0);}
	void ini(int _n=N){fill(h,h+(n=_n),-1);e=0;}
	bool bfs(){
		int L=0,R=0;
		fill(level,level+n,-1);level[q[R++]=s]=0;
		while(L<R&&level[t]==-1){
			int c=q[L++];
			for(int k=h[c];~k;k=ne[k])if(cap[k]>0&&level[to[k]]==-1)
				level[q[R++]=to[k]]=level[c]+1;
		}
		return ~level[t];
	}
	T dfs(int c,T mx){
		if(c==t)return mx;
		T ret=0;
		for(int &k=cur[c];~k;k=ne[k]){
			if(level[to[k]]==level[c]+1&&cap[k]>0){
				T flow=dfs(to[k],min(mx,cap[k]));
				ret+=flow;cap[k]-=flow,cap[k^1]+=flow;mx-=flow;
				if(!mx)return ret;
			}
		}
		level[c]=-1;
		return ret;
	}
	T run(int _s,int _t){
		s=_s,t=_t,flow=0;
		while(bfs()){
			copy(h,h+n,cur);flow+=dfs(s,~0U>>1);
		}
		return flow;
	}
};
dinic<int> M;
vector<pii> V[505];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		V[c].pb(mp(a,b));
	}
	int ans=0;
	rep(i,1,505)rep(j,0,sz(V[i]))
	{
		M.ini();
		rep(I,0,i)rep(J,0,sz(V[I]))M.link(V[I][J].first,V[I][J].second,1),M.link(V[I][J].second,V[I][J].first,1);
		ans+=M.run(V[i][j].first,V[i][j].second);
	}
	printf("%d\n",ans);
	return 0;
}
