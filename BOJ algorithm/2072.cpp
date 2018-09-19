#include <iostream>
using namespace std;
bool check(int arr[][32], int color, int x, int y) {
	int count = 0;
	int max = 0;
	if (arr[x - 5][y] != color) {
		for (int i = -4; i < 5; i++) {
			if (arr[x + i][y] == color) count++;
			else count = 0;
			if (count == 5 & arr[x + i + 1][y] != color) return true;
		}
	}
	if (arr[x][y - 5] != color) {
		for (int i = -4; i < 5; i++) {
			if (arr[x][y + i] == color) count++;
			else count = 0;
			if (count == 5 & arr[x][y + i + 1] != color) return true;
		}
	}
	if (arr[x - 5][y - 5] != color) {
		for (int i = -4; i < 5; i++) {
			if (arr[x + i][y + i] == color) count++;
			else count = 0;
			if (count == 5 & arr[x + i + 1][y + i + 1] != color) return true;
		}
	}
	if (arr[x - 5][y + 5] != color) {
		for (int i = -4; i < 5; i++) {
			if (arr[x + i][y - i] == color) count++;
			else count = 0;
			if (count == 5 & arr[x + i + 1][y - i - 1] != color) return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr[32][32] = { 0, }; // [6][6]~[24][24]
	int x, y;
	bool color = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr[x + 6][y + 6] = color + 1;
		if (check(arr, color + 1, x + 6, y + 6)) {
			cout << i + 1 << '\n';
			return 0;
		}
		color = !color;
	}
	cout << -1 << '\n';
	return 0;
}