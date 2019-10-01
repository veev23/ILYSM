#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
A + B * x < C * x
(C-B) * x > A
x > A/(C-B)
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B, C;
	cin >> A >> B >> C;
	if (C - B <= 0) cout << -1;
	else
		cout << A / (C - B) + 1;
	return 0;
}
