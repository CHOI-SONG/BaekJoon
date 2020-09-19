#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int m, n, k;
int c;
int arrCount = 0;
int map[110][110];
int arr[10000];
int moveX[4] = { 0, 1, 0, -1 }; // x��ǥ ���� 
int moveY[4] = { 1, 0, -1, 0 }; // y��ǥ ����  
 
void DFS(int a, int b)
{
	// Ż�� ����: �湮�� �� ���� �����  
	if (map[a][b] == 0) {
		map[a][b] = 1;
		++c; // �湮�� �� ���� �� 1�� üũ�ϰ� ���� �� �ø���  
		for (int l = 0; l < 4; ++l) { // �ش���ġ�κ��� ����, ������, �Ʒ���, ���� Ž�� ������  
			int x = moveX[l] + a; // �̰� �˰ھ�  
			int y = moveY[l] + b;
			if (x >= 0 && y >= 0 && x < m && y < n) { // (5, 5) ������ ���� ��
		 		// �ش� ������ ��� ��ǥ ��� �ȿ� ������ Ž�� �ٽ� ����
				// ��� ������ ���� ���� Ž��  
				DFS(x, y);
			}
		}
	}
}
 
int main(int argc, char *argv[])
{
	int x1, y1, x2, y2;
 	
	memset(map, 0, sizeof(map));
	memset(arr, 0, sizeof(arr));
 
 	freopen("input.txt", "rt", stdin); 
	cin >> m;
	cin >> n;
	cin >> k;
 
	while (k--) {
		cin >> x1 >> y1;
		cin >> x2 >> y2;
 
		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j) {
				map[j][i] = 1; // �ϴ� �簢������ 1�� ä���  
				printf("x: %d y: %d\n", i, j); // ���� ���ڰ� ū ��ǥ x, y�� ���ؼ��� ī��Ʈ ���� ����  
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == 0) { // 1 �ƴ�, �簢�� ������ ���Ե��� �ʴ� �κе��� ������ ã�� ���� DFS Ž�� ������ 
				c = 0; // �ϴ� ���� ���� 0���� ����  
				// �ܼ��� ���ڸ� ���°� ��� �簢���� ��ü ���̸� ���� ���� ���ذ� �ȵ�  
				DFS(i, j);
				arr[arrCount++] = c; // �������� ������ �迭�� ������ ���� �����ϱ�  
			}
		}
	}
	sort(arr, arr + arrCount); // ���ڰ� ���̱� ���� �����ϱ�  
 
	cout << arrCount << endl;
 
	for (int i = 0; i < arrCount; ++i) {
		cout << arr[i] << " "; // ���� �ϳ��� ���� ������ ����ϱ�  
	}
 
	return 0;
}
