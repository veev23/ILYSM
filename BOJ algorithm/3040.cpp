#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	//7���� ���� 100�̾�� �ϹǷ� 9���� 2���� ���� 100�̶�� �� �θ��� ��¥
	int arr[9];
	int total=0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	int a=0, b=0;
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (total - arr[i] - arr[j] == 100) {
				a = i;
				b = j;
				break;
			}
		}
		if (a) break;
	}
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		cout << arr[i] << '\n';
	}
	return 0;
}