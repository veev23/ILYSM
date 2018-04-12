#include <iostream>
#include <ctime>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	srand(time(NULL));
	int n;
	cin >> n;
	int arr[10005] = { 0, };
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a]++;
	}
	for (int i = 0; i <= 10000; i++) {
		while(arr[i]--) 
			cout << i << '\n';
	}
	return 0;
}