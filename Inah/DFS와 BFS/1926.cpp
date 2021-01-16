#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m, cnt = 0;
int map[503][503], chk[503][503] = { 0 };
vector<int> v;

bool compare(int x, int y)
{
	return y < x;
}
void DFS(int x, int y)
{
	chk[x][y] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (map[nx][ny] && !chk[nx][ny]) DFS(nx, ny);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && !chk[i][j]) {
				cnt = 0;
				DFS(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end(), compare);

	cout << v.size() << endl;
	if (v.size() > 0) cout << v[0];
	else cout << 0;

	return 0;
}
