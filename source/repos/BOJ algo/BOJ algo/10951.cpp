#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int a, b;
	while(cin >> a >> b){
		cout << a + b << '\n';
	}
	return 0;
}