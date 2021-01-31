#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > tree(50);
int cnt = 0;
void dfs(int x) {
	if (tree[x].size() == 1) {
		cnt++;
		return;
	}
	for (int i = 1; i < tree[x].size(); i++) {
		dfs(tree[x][i]);
	}
}

int main() {
	for (int i = 0; i < 50; i++) {
		vector<int>tmp = { 0 };
		tree[i] = tmp;
	}
	int N; // 노드 수;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		tree[i][0] = parent;
		if (parent != -1)
			tree[parent].push_back(i);
	}
	int dl;
	cin >> dl; // 삭제할 노드
	if (N == 1) {
		cout << 0;
		return 0;
	}
	int tmp = tree[dl][0]; // 삭제 노드의 부모
	if (tmp == -1) {
		cout << 0;
		return 0;
	}
	int index = 1;
	while (tree[tmp][index] != dl)
		index++;
	tree[tmp][index] = tree[tmp].back();
	tree[tmp].pop_back(); // 노드 자르기
	index = 0;
	while (tree[index][0] != -1)
		index++;
	dfs(index);
	cout << cnt;
}
