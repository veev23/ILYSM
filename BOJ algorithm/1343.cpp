#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str, ans;
bool check(int start, int sz) {
	int checked = 0;
	while (str[start++] == 'X' && ++checked < sz);
	return checked == sz;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '.') {
			ans += '.';
		}
		else if (check(i, 4)) {
			ans += "AAAA";
			i += 3;
		}
		else if (check(i, 2)) {
			ans += "BB";
			i += 1;
		}
		else {
			cout << "-1";
			return 0;
		}
	}
	cout << ans;
	return 0;
}
