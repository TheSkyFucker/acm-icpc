// index : [0, n)
void ini(string s, int p[]) {
  int t = -1; p[0] = -1;
  rep(i, 1, sz(s)) {
    while (~t && s[t + 1] != s[i]) t = p[t];
    p[i] = t += (s[t + 1] == s[i]);
  }
}
