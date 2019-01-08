#include <iostream>
#include <vector>
using namespace std;
#define	UP	0
#define LEFT	1
#define DOWN	2
#define RIGHT	3
#define WALLCRASH 1
#define ROBOTCRASH 2
//반시계방향 +, 시계방향 -
struct robot {
	int x; int y; int d;
};
robot* ddang[101][101] = { 0 };
vector<robot> robo;
void turn(int roboNum, char dir, int repeat) {
	repeat %= 4;
	for (int i = 0; i < repeat; i++) {
		if (dir == 'L')robo[roboNum-1].d++;
		else robo[roboNum - 1].d--;
		if (robo[roboNum - 1].d > 3) robo[roboNum - 1].d -= 4;
		else if (robo[roboNum - 1].d < 0) robo[roboNum - 1].d += 4;
	}
}
int foward(int roboNum, int repeat, int max_x, int max_y) {
	for (int i = 0; i < repeat; i++) {
		int n_x;
		int n_y;
		if (robo[roboNum - 1].d == UP) {
			n_x = robo[roboNum - 1].x;
			n_y = robo[roboNum - 1].y + 1;
		}
		else if (robo[roboNum - 1].d == LEFT) {
			n_x = robo[roboNum - 1].x - 1;
			n_y = robo[roboNum - 1].y;
		}
		else if (robo[roboNum - 1].d == DOWN) {
			n_x = robo[roboNum - 1].x;
			n_y = robo[roboNum - 1].y - 1;
		}
		else {
			n_x = robo[roboNum - 1].x + 1;
			n_y = robo[roboNum - 1].y;
		}
		if (n_x > max_x || n_x<1 || n_y>max_y || n_y < 1) {
			cout << "Robot " << roboNum << " crashes into the wall\n";
			return WALLCRASH;
		}
		else if (ddang[n_x][n_y] != NULL) {
			for (int i = 0; i < robo.size(); i++) {
				if (robo[i].x == n_x && robo[i].y == n_y) {
					cout << "Robot " << roboNum << " crashes into robot " << i + 1<<'\n';
					return ROBOTCRASH;
				}
			}
		}
		ddang[robo[roboNum - 1].x][robo[roboNum - 1].y] = NULL;
		ddang[n_x][n_y] = &robo[roboNum - 1];
		robo[roboNum - 1].x = n_x;
		robo[roboNum - 1].y = n_y;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		char d;
		int dir;
		cin >> x >> y >> d;
		if (d == 'E')	dir = RIGHT;
		else if (d == 'W') dir = LEFT;
		else if (d == 'N') dir = UP;
		else dir = DOWN;
		robot tmp = robot{ x,y,dir };
		robo.push_back(tmp);
		ddang[x][y] = &tmp;
	}
	int ERROR = 0;
	for (int i = 0; i < m; i++) {
		int roboNum, repeat;
		char order;
		cin >> roboNum >> order >> repeat;
		if (order == 'F') ERROR = foward(roboNum, repeat, a, b);
		else turn(roboNum, order, repeat);
		if (ERROR) break;
	}
	if (!ERROR) cout << "OK\n";
}
