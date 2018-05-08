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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  unordered_map<string, string> Map;
  
  while (1) {
  	string s; getline(cin, s);
  	if (s == "@END@") break;
  	int i = 0; while (s[i] != ']') i++;
  	string a = s.substr(0, i + 1);
  	string b = s.substr(i + 2);
		Map[a] = b;
		Map[b] = a;
	}
	int n; cin >> n;
	cin.ignore(1024, '\n');
	rep(i, 0, n) {
		string s; getline(cin, s);
		if (!Map.count(s)) { cout << "what?" << endl; continue; }
		else {
			string d = Map[s];
			if (d[0] == '[') {
				d = d.substr(1, sz(d) - 2);
			}
			cout << d << endl;
		}
	}
	return 0;
}
