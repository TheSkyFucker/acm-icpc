// description : the xor-sum of [1, n] || [l, r]
// time : O(1)
ll f(ll n) { return n & 1 ? f(n - 1) ^ n : n + (n >> 1 & 1); }
ll f(ll l, ll r) { return f(r) ^ (l > 0 ? f(l - 1) : 0); }
