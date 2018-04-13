#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	int row, col;
	row = n / 2;
	col = n - row;
	cout << (row + 1)*(col + 1)<<'\n';//±ÔÄ¢¼º
	return 0;
}