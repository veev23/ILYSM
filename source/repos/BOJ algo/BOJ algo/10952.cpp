#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		cout << a + b << '\n';
	}
	return 0;
}