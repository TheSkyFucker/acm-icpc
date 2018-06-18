// desc : block initial
const int BSZ = 2000, N = 2e5 + 7;
int n, bn, b[N], bl[N], br[N];
void ini() {
	bn = (n - 1) / BSZ + 1;
	rep(i, 0, bn) {
		bl[i] = i * BSZ;
		br[i] = min(n, (i + 1) * BSZ);
		rep(j, bl[i], br[i]) b[j] = i;
	}
}
