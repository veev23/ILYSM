#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool strcmp(char* a, char* b, int size) {
	while (size && *a && *b && *a++ == *b++){
		--size;
	};
	return size == 0;
}
int solve() {
	string str, find;
	int cnt = 0;
	getline(cin, str);
	getline(cin, find);
	int sz = find.length();
	for (register int i = 0; i < str.length(); ++i) {
		if (strcmp(&str[i], &find[0], sz)) {
			i += sz - 1;
			++cnt;
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << solve();
	return 0;
}
