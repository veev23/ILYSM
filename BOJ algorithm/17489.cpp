#include <iostream>
using namespace std;
struct pos {
	int y; int x;
};
int dy[] = { 0,0,1,-1 };
int dx[] = { 1, -1, 0,0 };
int n, m;
char arr[101][101], visit[101][101];
char str[28];
int str_len;
int max_k = 0;
pos max_pos;
bool change_flag = false;
bool cycle = false;
//pos : 좌표, l : str에서 진행할 idx, k : 반복횟수
void char_dfs(pos p, int l, int k) {
	if (l == str_len) {
		l = 0; ++k;
	}
	for (int i = 0; i < 4; ++i) {
		pos np = { p.y + dy[i], p.x + dx[i] };
		if (np.y < 0 || np.x < 0 || np.y >= n || np.x >= m || arr[np.y][np.x] != str[l]) continue;
		if (l == 0 && visit[np.y][np.x]) {
			cycle = true;
			continue;
		}
		if (l == 0) visit[np.y][np.x] = true;
		char_dfs(np, l + 1, k);
		if(l == 0) visit[np.y][np.x]= false;
	}
	if (max_k < k && !cycle) {
		max_k = k;
		change_flag = true;
	}
	if (max_k == k && l == 0 && change_flag) {
		change_flag = false;
		max_pos = p;
	}
	return;
}
void solve() {
	pos p{ 0,0 };
	visit[0][0] = true;
	char_dfs(p, 1, 0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> str_len >> str;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	solve();
	if (max_k > 0) {
		cout << max_k << '\n' << max_pos.y+1 << " " << max_pos.x+1;
	}
	else cout << "-1";
	return 0;
}
