#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
bool have_zero() {
	for (char i : str) {
		if (i == '0') return true;
	}
	return false;
}
bool is_multiple_of_3() {
	int sum = 0;
	for (char i : str) {
		sum += i - '0';
	}
	return !(sum % 3);
}
string solve() {
	cin >> str;
	if (!have_zero() || !is_multiple_of_3()) return "-1";
	sort(str.begin(), str.end(), greater<char>());
	return str;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << solve();
	return 0;
}
