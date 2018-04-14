#include <iostream> 
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	int strleng = str.length();
	switch (str[0]) {
	case '0': cout << '0'; break;
	case '1': cout << "1"; break;
	case '2': cout << "10"; break;
	case '3': cout << "11"; break;
	case '4': cout << "100"; break;
	case '5': cout << "101"; break;
	case '6': cout << "110"; break;
	case '7': cout << "111"; break;
	}
	for (int i = 1; i < strleng; i++) {
		switch (str[i]) {
		case '0': cout << "000"; break;
		case '1': cout << "001"; break;
		case '2': cout << "010"; break;
		case '3': cout << "011"; break;
		case '4': cout << "100"; break;
		case '5': cout << "101"; break;
		case '6': cout << "110"; break;
		case '7': cout << "111"; break;
		}
	}
	return 0;
}
