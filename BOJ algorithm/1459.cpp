#include <iostream>
#include <algorithm>
using namespace std;
long long int x, y, s, w;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y >> w >> s;
	long long int min_pos = min(x, y);
	long long int max_pos = max(x, y);
	if (s >= w * 2) {
		cout << w * (x + y);
	}
	else if (s <= w) {
		cout << min_pos * s + s * ((max_pos - min_pos)/2) * 2 + w * ((max_pos - min_pos)%2);
	}
	else {
		cout << min_pos * s + w * (max_pos - min_pos);
	}
	return 0;
}
