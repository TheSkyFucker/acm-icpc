#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(int i=(l);i<(r);++i)
int n, m;
ll gao(int d) { return m - d + (d * 2 < m ? gao(d * 2) : 0); }
int main() {
  scanf("%d%d", &n, &m);
  int a, d = 0; 
  rep(i, 0, n) scanf("%d", &a), d = __gcd(a - 1, d);
  d >>= __builtin_ctz(d);
  ll ans = 0;
  for (int i = 1; i * i <= d; i++) if (d % i == 0) {
	ans += gao(i);
	if (i * i != d) ans += gao(d / i);
  }
  printf("%lld", ans);
  return 0;
}
