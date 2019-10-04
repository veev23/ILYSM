#include <iostream>
#include <algorithm>
using namespace std;
#define LEFT 0
#define STR 1
#define RIGHT 2
#define MAX 987654321
int n,m, m_val=MAX, arr[1002][1002], dp[1002][1002][3];
//dp[i][j][dir] : i행 j열 칸 기준 dir방향에서 내려온 최소 누적 값 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			cin >> arr[i][j];
	for (register int i = 1; i <= n+1; ++i)
		for (register int j = 1; j <= m; ++j)
			for (register int k = 0; k < 3; ++k)
				dp[i][j][k] = MAX;
	for (register int i = 1; i <= n+1; ++i) {
		for (register int j = 1; j <= m; ++j) {
			for (register int dir = 0; dir < 3; ++dir) {
				if (j + dir - 1 == 0 || j + dir - 1 == m+1) continue;
				for (register int k = 0; k < 3; ++k) {
					if (dir == k) continue;
					dp[i][j][dir] = min(dp[i][j][dir], dp[i - 1][j + dir - 1][k] + arr[i][j]);
				}
			}
		}
	}
	for (register int j = 1; j <= m; ++j) {
		for (register int dir = 0; dir < 3; ++dir) {
			m_val = min(m_val, dp[n + 1][j][dir]);
		}
	}
	cout << m_val;
	return 0;
}
