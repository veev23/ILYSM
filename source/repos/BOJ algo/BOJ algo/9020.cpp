#include <iostream>
#include <cmath>
using namespace std;
int arr[10000];
int main() {
	ios::sync_with_stdio(false);
	int k;
	for (int i = 2; i < 10000; i++) arr[i] = 1;
	for (int i = 2; i < 10000; i++) {
		if (arr[i] == 1) {
			k = i + i;
			while (k < 10000) {
				arr[k] = 0;
				k += i;
			}
		}
	}
	int T, n, min[3];// 0:Â÷, 1:a, 2:b
	cin >> T;
	while (T--) {
		cin >> n;
		min[0] = 10000;
		for (int i = n/2; i > 1; i--) {
			for (int j = n/2; j < n; j++) {
				if (arr[i] && arr[j] && (i + j == n)) {
					//if (min[0] > j - i) {
						min[0] = j - i;
						min[1] = i;
						min[2] = j;
						i = 1;
						break;
					//}
				}
			}
		}
		cout << min[1] << ' ' << min[2] << '\n';
	}
	return 0;
}