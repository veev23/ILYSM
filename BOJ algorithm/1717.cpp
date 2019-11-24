#include <iostream>
using namespace std;
int n, m, par[1000001], cmd, a, b;
void init() {
	for (int i = 1; i <= n; i++) par[i] = i;
}
int find(int n) {
	if (par[n] == n) return n;
	return par[n] = find(par[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	par[b] = a;
}
void solve() {
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		cin >> cmd >> a >> b;
		switch (cmd) {
		case 0:
			merge(a, b);
			break;
		case 1:
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}
