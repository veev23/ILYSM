#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int arr[10001];
	int a, b;
	cin >> a >> b;
	for (int i = 2; i < 10001; i++) arr[i] = 1;
	int k;
	for (int i = 2; i < 10001; i++) {
		if (arr[i] == 1) {
			k = i + i;
			while (k < 1001) {
				arr[k] = 0;
				k += i;
			}
		}
	}
	int min = 0;
	int total = 0;
	for (int i = a; i < b+1; i++) {
		if (arr[i] == 1) {
			min = (min == 0 ? i : min);
			total += i;
		}
	}
	if (total == 0) cout << "-1";
	else cout << total << '\n' << min;
	return 0;
}