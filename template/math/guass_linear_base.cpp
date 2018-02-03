// b[i] : the base of i-th bit
// time : O(n * B + B * B)
// !!!! : use before ini() !
struct GuassLB {
  static const int B = 64;
  ll b[B] , sz;
  void ini()  { fill_n(b, B, 0); }
  void add(ll a) {
    per(i, 0, B) if((a >> i) & 1) {
      if (b[i]) a ^= b[i]; else {
        b[i] = a;
        per(j, 0, i) if(b[j] && (b[i] & pw(j))) b[i] ^= b[j];
        per(j, i + 1, B) if (b[j] & pw(i)) b[j] ^= b[i];
        break;
      }
    }
  }
  ll kth(ll k) {
    vi v; rep(i, 0, B) if (b[i]) v.pb(i);
    ll r = 0, mask = pw(sz(v)) - 1 - k;
    rep(i,0,sz(v)) if(mask & pw(i)) r ^= b[v[i]];
    return r;
  }
}	gs;
