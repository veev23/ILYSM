#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct rotate_data {
	int r; int c; int s;
};
rotate_data rd[6];
int arr[51][51];
int N, M, K;
int min_val = 12345678;
bool visit[6];
void rotate(int r, int c, int s) {
	for (int size = 1; size <= s; ++size) {
		int tmp = arr[r - size][c + size]; //북동쪽 인자 기억
		//위쪽라인
		for (register int i = size; i > -size; --i) {
			arr[r - size][c + i] = arr[r - size][c + i - 1];
		}
		//왼쪽라인
		for (register int i = -size; i < size; ++i) {
			arr[r + i][c - size] = arr[r + i + 1][c - size];
		}
		//아래쪽라인
		for (register int i = -size; i < size; ++i) {
			arr[r + size][c + i] = arr[r + size][c + i + 1];
		}
		//오른쪽라인
		for (register int i = size; i > -size; --i) {
			arr[r + i][c + size] = arr[r + i - 1][c + size];
		}
		arr[r - size + 1][c + size] = tmp;
	}
}
void inverse_rotate(int r, int c, int s) {
	for (int size = 1; size <= s; ++size) {
		int tmp = arr[r - size][c - size]; //북서쪽 인자 기억
		//위쪽라인
		for (register int i = -size; i < size; ++i) {
			arr[r - size][c + i] = arr[r - size][c + i + 1];
		}
		//오른쪽라인
		for (register int i = -size; i <size; ++i) {
			arr[r + i][c + size] = arr[r + i + 1][c + size];
		}
		//아래쪽라인
		for (register int i = size; i > -size; --i) {
			arr[r + size][c + i] = arr[r + size][c + i - 1];
		}
		//왼쪽라인
		for (register int i = size; i > -size; --i) {
			arr[r + i][c - size] = arr[r + i - 1][c - size];
		}
		arr[r - size + 1][c - size] = tmp;
	}
}
int get_value() {
	int min_val = 12345678;
	for (register int i = 1; i <= N; ++i) {
		int sum = 0;
		for (register int j = 1; j <= M; ++j) {
			sum += arr[i][j];
		}
		min_val = min(min_val, sum);
	}
	return min_val;
}
void dfs(int depth) {
	if (depth == K) {
		min_val = min(min_val, get_value());
		return;
	}
	for (int i = 0; i < K; ++i) {
		if (visit[i]) continue;
		visit[i] = true;
		rotate(rd[i].r, rd[i].c, rd[i].s);
		dfs(depth + 1);
		inverse_rotate(rd[i].r, rd[i].c, rd[i].s);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for (register int i = 1; i <= N; i++) {
		for (register int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	for (register int i = 0; i < K; ++i) {
		cin >> rd[i].r >> rd[i].c >> rd[i].s;
	}
	dfs(0);
	cout << min_val;
	return 0;
}
