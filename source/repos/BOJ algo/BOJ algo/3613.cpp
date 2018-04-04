#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();

	string str, str2 = "";
		cin >> str;
		int upcount = 0;
		int underbarcount = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] <= 'Z') upcount++;
			if (str[i] == '_') underbarcount++;
		}
		if (upcount*underbarcount) {
			cout << "Error!\n";
			return 0;
		}

		if (str[str.length() - 1] == '_' || str[0] == '_' || str[0] <= 'Z') {
			cout << "Error!\n";
			return 0;
		}

		int i = 0;
		while (str[i]) {
			if (str[i] == '_') {
				if (str[i + 1] == '_') {
					cout << "Error!\n";
					return 0;
				}
				str2 += str[i + 1] - 32;
				i++;
			}
			else if (str[i] <= 'Z') {
				str2 += '_';
				str2 += str[i] + 32;
			}
			else
				str2 += str[i];
			i++;
		}
		cout << str2 << '\n';
	return 0;
}