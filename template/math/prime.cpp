// time : O(n)
// low[] : optional
const int N = 1e6 + 6;
int low[N], isp[N]; vi pri;
void getprime() {
	fill_n(isp + 2, N - 2, 1);
	rep(i, 2, N) {
		if (isp[i]) pri.pb(i);
		for (auto p : pri) {
			if (p * i >= N) break;
			//low[p * i] = p;
			isp[p * i] = 0;
			if (i % p == 0) break;
		}
	}
}

