#include <iostream>
using namespace std;
int remain[42], input, diff=0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 10; ++i) {
		cin >> input;
		++remain[input % 42];
	}
	for (int i = 0; i < 42; ++i) {
		if (remain[i]) ++diff;
	}
	cout << diff;
	return 0;
}
