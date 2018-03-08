// index : [0, n)
int pre[N];
void ini(char str[]) {
	int n = strlen(str), tmp = -1;
	pre[0] = -1;
	rep(i, 1, n) {
		for (; ~tmp && str[tmp + 1] != str[i]; tmp = pre[tmp]);
		pre[i] = tmp += (str[tmp + 1] == str[i]);
	}
}
