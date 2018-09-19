#include <iostream>
#include <cmath>
using namespace std;
int arr[1000001];
int main() {
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	for (int i = 2; i < b+1; i++) arr[i] = 1;
	int k;
	for (int i = 2; i < b+1; i++) {
		if (arr[i] == 1) {
			k = i + i;
			if(i>=a) cout << i << '\n';
			while (k < b+1) {
				arr[k] = 0;
				k += i;
			}
		}
	}
	return 0;
}