#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string str, cmp;
	cin >> str;
	int star=0;
	while (str[star] != '*') star++;
	string s1, s2;
	for (int i = 0; i < star; i++) s1 += str[i];
	for (int i = star+1; str[i]; i++) s2 += str[i];
	for (int i = 0; i < n; i++) {
		cin >> cmp;
		int flag = 0;
		int cmplen = cmp.length();
		int len = s1.length();
		if (cmplen < len + s2.length()) flag = 1;
		if (flag == 0) {
			for (int j = 0; j < len; j++) {
				if (cmp[j] != s1[j]) {
					flag = 1;
				}
			}
			len = s2.length();
			for (int j = cmplen - 1; len > 0; j--, len--) {
				if (cmp[j] != s2[len - 1]) {
					flag = 1;
				}
			}
		}
		if (flag == 0) cout << "DA\n";
		else cout << "NE\n";
	}
	return 0;
}