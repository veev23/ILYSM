#include <iostream>
#include <string>
using namespace std;
struct stack {
	char data[60];
	int top = -1;
	void push(char d) {
		data[++top] = d;
	}
	char pop() {
		if (top < 0) return '\0';
		else return data[top--];
	}
	void clear() {
		top = -1;
	}
	bool isEmpty() {
		return (top == -1);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string str;
	stack s;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int j = 0;
		int flag = 0;
		while (str[j]) {
			if (str[j] == '(') {
				s.push(str[j]);
			}
			else {
				if (s.pop() == '\0') {
					flag = 1;
					break;
				}
			};
			j++;
		}
		if(s.isEmpty() && flag == 0)
			cout << "YES\n";
		else cout << "NO\n";
		s.clear();
	}
	return 0;
}