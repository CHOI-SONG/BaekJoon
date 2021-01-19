#include <iostream>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int m, n;
int map[501][501], dp[501][501];

int DFS(int x, int y)
{
	if (x == m - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

		if (map[nx][ny] < map[x][y]) dp[x][y] = dp[x][y] + DFS(nx, ny);
	}
	return dp[x][y];
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(0, 0);

	return 0;
}
