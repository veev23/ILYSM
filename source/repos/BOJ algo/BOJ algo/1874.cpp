#include <iostream>
#include <string>
using namespace std;
struct stack {
	int data[100005];
	int top = -1;
	string remember;
	void push(int d) {
		data[++top] = d;
		remember+="+\n";
	}
	int pop() {
		if (top < 0) return -1;
		else {
			remember+="-\n";
			return data[top--];
		}
	}
	int topIs() {
		if (top < 0) return -1;
		return data[top];
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
	int arr[100005];
	for (int i = 0; i < n; i++)cin >> arr[i];
	stack s;
	int k = 1;
	int i = 0;
	s.push(k++);
	while(i < n) {
		if (arr[i] == k) {
			s.push(k++);
			s.pop();
			i++;
		}
		if(arr[i] == s.topIs()){
			s.pop();
			i++;
		}
		else s.push(k++);
		if (s.topIs() > n) break;
	}
	if (s.isEmpty() == false) cout << "NO\n";
	else	cout << s.remember;
	return 0;
}