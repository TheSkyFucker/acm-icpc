// desc : 
//   1. use rep(b, 0, bn) 
//   2. use b*[b] to store info of block b
// check :
//   1. b*[b], not b*[i]
//   2. different BSZ (especially 1)

const int BSZ = 700, N = 1e5 + 7;
int bn, bl[N], br[N], sz[N];

void ini(int n) {
  bn = (n - 1) / BSZ + 1;
  rep(i, 0, n) a[i] = 0;
  rep(b, 0, bn) {
    bl[b] = b * BSZ;
    br[b] = min(n, (b + 1) * BSZ);
    sz[b] = br[b] - bl[b];
  }
}

//rebuild block b
void bud(int b) { }

// change [l, r) in block b : rep(b, 0, bn) chg(b, ql, qr);
void chg(int b, int l, int r) {
  int nl = max(l, bl[b]);
  int nr = min(r, br[b]);
  if (nl >= nr) return;
  if (nr - nl == sz[b]) {
    // chg whole block
  }
  else {
    // mybey bud(b)
    // chg [nl, nr)
  }
}

// query [l, r) in block b : rep(b, 0, bn) qry(b, ql, qr);
? qry(int b, int l, int r) {
  int nl = max(l, bl[b]);
  int nr = min(r, br[b]);
  if (nl >= nr) return 0;
  if (nr - nl == sz[b]) {
    // qry whole block
  }
  else {
    bud(b);
    // qry [nl, nr)
  }
}
