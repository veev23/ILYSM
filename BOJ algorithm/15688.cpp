#include <iostream>
#include <string>
using namespace std;
int num[1000005] = { 0, };
int _num[1000005] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k < 0) _num[~k+1]++;
		else num[k]++;
	}
	for (int i = 1000001; i > 0; i--) {
		while (_num[i] > 0) {
			cout << '-' << i << '\n';
			_num[i]--;
		}
	}
	for (int i = 0; i < 1000005; i++) {
		while (num[i] > 0) {
			cout << i << '\n';
			num[i]--;
		}
	}
	return 0;
}