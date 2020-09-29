#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue> 
#include <algorithm>
using namespace std;

int N;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int visit[101][101];
int map[101][101];
queue<pair<int, int> >q;

void bfs(int x,int y,int hei){
    q.push(make_pair(x,y));
    visit[x][y] = 1; // �湮 üũ  
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        // �ش� ���� ť�� �ְ� 
        q.pop();
        // ���鼭 
		
		// �ش� ���� ������ ���� ã�� ������  
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            // �� �Ʒ� ���� �������̾�� �ϰ�  
            if(nx>0 && nx<=N && ny>0 && ny<=N){
            	// ���õ� ���̺��� Ŀ�ߵǰ�,�湮�� ���� ���� ���� ��쿡��  
                if(map[nx][ny]>hei && visit[nx][ny] == 0){
                	// �湮 ǥ���ϰ�  
                	visit[nx][ny] = 1;
                    // �ش� ���� �� �ִ´� 
					q.push(make_pair(nx,ny));
                }
            }
        }
    }
}



int main(void){
	freopen("input.txt", "rt", stdin);
	int height = 0;
    int count = 0;
    int max_c = 0;
	scanf("%d", &N);
	
	int min_height=100,max_height=1;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
			if(height<=map[i][j])
				height=map[i][j];
		}
	}
	
	// ���� ū ���� ����  
	
	// 0���� ���� ��ŭ �ݺ��ϸ鼭 �ִ� ���ᰳ�� ���ϱ�  
	for(int h=0;h<=height;h++){
        count = 0;
        // �Ź� ���� �������� �湮 �迭 �ʱ�ȭ  
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                visit[i][j] = 0;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            	// �湮�� �� ���� Ư�� ���̺��� Ŭ ���  
                if(map[i][j]>h && visit[i][j] == 0){
                    count++;
                    bfs(i,j,h); // �ش� ���� ���̿� ���� BFS Ž�� ����  
                }
        if(max_c <= count)
            max_c = count;
    }
    printf("%d", max_c);

}


