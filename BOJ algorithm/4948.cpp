#include <iostream>
#include <cmath>
using namespace std;
int arr[250000];
int main() {
	ios::sync_with_stdio(false);
	int k;
	for (int i = 2; i < 250000; i++) arr[i] = 1;
	for (int i = 2; i < 250000; i++) {
		if (arr[i] == 1) {
			k = i + i;
			while (k < 250000) {
				arr[k] = 0;
				k += i;
			}
		}
	}
	int n, count;
	cin >> n;
	while (n != 0) {
		count = 0;
		for (int i = n+1; i < 2 * n + 1; i++) {
			if (arr[i] == 1) count++;
		}
		cout << count << '\n';
		cin >> n;
	}
	return 0;
}