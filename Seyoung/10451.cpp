#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

bool visited[1001];
int array[1001];

bool DFS(int n){
	visited[n]=true;
	
	int next = array[n];
	if(!visited[next]){
		DFS(next);
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	int T, n, a;
	scanf("%d", &T);
	
	
	// ������ �ᱹ �������� �迭�ε�, �̰� ��� �׷����� �����ϳ� �ߴ���
	// arr[1] = 3 �ϸ� �迭 1�� ��ġ�� 3���� �����ϰ�
	// arr[arr[1]] �� �ҷ����̸� arr[1]�� ���� �����,
	// ��������δ� arr[3] �� �ҷ����̴� �� 
	
	 
	for(int i=1; i<=T; i++){
		scanf("%d", &n); // ���� �迭 ����
		
		// �迭 ������ŭ �Է¹ޱ�  
		for(int j=1; j<=n; j++){
			scanf("%d", &array[j]);
		}
		
		memset(visited, false, sizeof(visited)); // visited �迭 �ʱ�ȭ 
		
		int cnt=0; // ���� ����Ŭ ����
		
		for(int k=1; k<=n; k++){
			if(!visited[k]){
				DFS(k);
				cnt++;
			}
		}
		
		printf("%d\n", cnt);
	} 

	return 0;
} 	

