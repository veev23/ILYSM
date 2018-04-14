#include <iostream> 
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int arr[105];
	int ktotal=0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) ktotal += arr[i];
	int max = ktotal;
	for (int i = k; i < n; i++) {
		ktotal = ktotal + arr[i] - arr[i - k];
		if (max < ktotal) max = ktotal;
	}
	cout << max << '\n';
	return 0;
}
