#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	char input[40];
	string str[8];
	cin >> input;
	int k = 0;
	int i = 0;
	while(true){
		while (input[k] != ':') {
			if (input[k]=='\0') break;
			str[i] += input[k++];
		}
		if (input[k] == ':') i++;
		if (input[k] == '\0') break;
		k++;
	}
	int remember = -1; //::의 위치
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (str[i].length()==0) {
			count++;
			if (remember == -1) remember = i;
		}
		else
			while(str[i].length() < 4) {
				str[i] = '0' + str[i];
			}
	}
	if (count == 0) count++;
	for (int i = 0; i < 9-count; i++) {
		if (i == remember && count > 0) {
			for (int j = 0; j < count; j++) {
				cout << "0000";
				if (i == 8 - count) break; 
				cout << ':';
			}
		}
		else cout << str[i];
		if (i == 8-count) continue;
		if(i!=remember)
			cout << ':';
	}
	cout << '\n';
	return 0;//마지막에 ::가 와서 0000:0000으로 마무리 하는 경우는 없음.
}