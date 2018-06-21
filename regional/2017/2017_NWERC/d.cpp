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
const int N=25;
string S[N];
map<string,pii> M;
map<string,string> MM;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	cin>>n;
	rep(i,0,n)cin>>S[i];
	int m;
	cin>>m;
	while(m--)
	{
		string a,b,c;
		cin>>a>>b>>c;
		if(c=="correct")M[a].fi++;
		else M[a].se++;
		MM[a]=b;
	}
	ll tot=1,ans=1;
	rep(i,0,n)
	{
		tot*=M[S[i]].fi+M[S[i]].se;
		ans*=M[S[i]].fi;
	}
	if(tot!=1)
	{
		cout<<ans<<" correct"<<endl;
		cout<<tot-ans<<" incorrect"<<endl;
	}
	else
	{
		rep(i,0,n)cout<<MM[S[i]]<<(i==n-1?"\n":" ");
		cout<<(ans?"correct":"incorrect")<<endl;
	}
	return 0;
}
