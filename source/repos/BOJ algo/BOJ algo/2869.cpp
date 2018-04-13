#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int a, b, v;
	cin >> a >> b >> v;
	if (a >= v) {
		cout << 1 << '\n';
		return 0;
	}
	v -= a;
	a -= b;
	if(v%a)
		cout << v / a + 2 << '\n';
	else
		cout << v / a + 1 << '\n';
	return 0;
}