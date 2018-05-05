
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
int n,x,y;
int now[10];
int M[10][10];
set<ll> S;
ll solve()
{
	ll ans=0;
	rep(i,0,4)rep(j,0,4)ans=ans*3+M[i][j]+1;
	return ans;
}
int isok()
{
	rep(i,0,4)if(M[i][1]==M[i][2]&&(M[i][1]==M[i][0]||M[i][1]==M[i][3])&&M[i][1]!=-1)return true;
	rep(i,0,4)if(M[1][i]==M[2][i]&&(M[1][i]==M[0][i]||M[1][i]==M[3][i])&&M[1][i]!=-1)return true;
	if(M[1][1]==M[2][2]&&(M[1][1]==M[0][0]||M[1][1]==M[3][3])&&M[1][1]!=-1)return true;
	if(M[0][1]==M[1][2]&&M[0][1]==M[2][3]&&M[0][1]!=-1)return true;
	if(M[1][0]==M[2][1]&&M[2][1]==M[3][2]&&M[1][0]!=-1)return true;
	if(M[1][2]==M[2][1]&&(M[1][2]==M[3][0]||M[1][2]==M[0][3])&&M[1][2]!=-1)return true;
	if(M[0][2]==M[1][1]&&M[1][1]==M[2][0]&&M[1][1]!=-1)return true;
	if(M[1][3]==M[2][2]&&M[2][2]==M[3][1]&&M[2][2]!=-1)return true;
	return false;
}
int dfs(int xx)
{
//	rep(i,0,4)printf("%d %d %d %d\n",M[i][0],M[i][1],M[i][2],M[i][3]);
//	puts("");
	rep(i,0,4)if(now[i]!=4)
	{
		M[i][now[i]++]=xx;
		if(xx==1&&i+1==x&&now[i]==y&&isok())S.insert(solve());
		else if(!isok())dfs(xx^1);
		M[i][--now[i]]=-1;
	}
}
int main()
{
	memset(M,-1,sizeof(M));
	scanf("%d%d%d",&n,&y,&x);
	rep(i,0,4)now[i]=0;
	M[n-1][now[n-1]++]=0;
	dfs(1);
	printf("%d\n",sz(S));
}
