#include <iostream>
using namespace std;
/*
+-+-+-+-+
|A|.|.|.|
+-+-+-+-+
|A|.|.|.|
+-+-+-+-+
|A|.|.|.|
+-+-+-+-+
|A|.|.|.|
+-+-+-+-+
*/
char arr[9][9];
int vertex_visit[5][5] = { 1 };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int dfs_visit[4][4];
int n;
bool dfs_check(char animal, int y, int x) {
	for (int i = 0; i < 4; ++i) {
		//방문한 곳인지?
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n
			|| dfs_visit[ny][nx])continue;
		//국경으로 가로막혀 있는지?
		int border_y = 1 + 2 * y + dy[i];
		int border_x = 1 + 2 * x + dx[i];
		if(arr[border_y][border_x] == '|' || arr[border_y][border_x] == '-')
			continue;
		//다른 동물인지?
		int big_ny = 1 + 2 * ny;
		int big_nx = 1 + 2 * nx; 
		dfs_visit[ny][nx] = true;
		if (arr[big_ny][big_nx] != '.' && arr[big_ny][big_nx] != animal) return false;
		if (!dfs_check(animal, ny, nx)) return false;
	}
	return true;
}
//같은 영역에 나와 다른 동물이 있는지?
bool is_ok() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dfs_visit[i][j] = false;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dfs_visit[i][j] || arr[1+i*2][1+j*2] =='.') continue;
			dfs_visit[i][j] = true;
			//불가능한 경우가 하나라도 있으면 false
			if (!dfs_check(arr[1 + i * 2][1 + j * 2],i,j)) return false;
		}
	}
	return true;
}
void init() {
	for (register int i = 0; i < 2*n+1; ++i) {
		for (register int j = 0; j <= 2*n+1; ++j) {
			arr[i][j] = ' ';
		}
	}
	for (register int i = 0; i <= n; ++i) {
		for (register int j = 0; j <= n; ++j) {
			arr[i * 2][j * 2] = '+';
		}
	}
}
bool back_tracking(int y, int x) {
	if (y == n && x == n) {
		return is_ok();
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny > n || nx > n || vertex_visit[ny][nx]) continue;
		vertex_visit[ny][nx] = true;
		if (dy[i])
			arr[2*y + dy[i]][2*x + dx[i]] = '|';
		else
			arr[2*y + dy[i]][2*x + dx[i]] = '-';
		//가능한 경우가 하나라도 있으면 true
		if(back_tracking(ny, nx)) return true;
		arr[2 * y + dy[i]][2 * x + dx[i]] = ' ';
		vertex_visit[ny][nx] = false;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	init();
	for (register int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i * 2 + 1][j * 2 + 1];
		}
	}
	if (back_tracking(0,0)) {
		cout << "yes\n";
		for (int j = 0; j < 4 * n + 3; ++j) cout << "#";
		cout << '\n';
		for (int i = 0; i < 2 * n + 1; ++i) {
			cout << '#';
			for (int j = 0; j < 2 * n + 1; ++j) {
				if (arr[i][j] == '-')
					cout << "---";
				else if (!(i%2) && arr[i][j] == ' ')
					cout << "   ";
				else if (arr[i][j] != '+' && arr[i][j] != '|'&&arr[i][j] != ' ')
					cout << ' ' << arr[i][j] << ' ';
				else
					cout << arr[i][j];
			}
			cout << '#';
			cout << '\n';
		}
		for (int j = 0; j < 4 * n + 3; ++j) cout << "#";
		cout << '\n';
	}
	else {
		cout << "no";
	}
	return 0;
}
