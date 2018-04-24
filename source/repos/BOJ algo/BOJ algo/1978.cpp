#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int arr[1001];
	for (int i = 2; i < 1001; i++) arr[i] = 1;
	int n;
	cin >> n;
	int k;
	int arr2[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	for (int i = 2; i < 1001; i++) {
		if (arr[i] == 1) {
			k = i + i;
			while (k < 1001) {
				arr[k] = 0;
				k += i;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[arr2[i]] == 1) {
			count++;
		}
	}
	cout << count;
	return 0;
}