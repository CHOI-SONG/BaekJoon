#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int map[50][50], ch[50][50];


int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
int w, h; //w, h

void DFS(int x, int y){
	int xx, yy;
	ch[x][y]=1;
	
	for(int i=0; i<8; i++){
		xx = x+dx[i];
		yy = y+dy[i];
			
		if(xx<0||xx>=h||yy<0||yy>=w) continue; 
		// ���� �Ѿ�� ������ 
		 
		if(ch[xx][yy]==0 && map[xx][yy]==1){
			DFS(xx, yy);
			// �ڷ� �� �͵� ���� ������ �ڵ� ��ȯ�� 
			// ������ ����� ���̸� ������ �� ���� ����Ǵϱ�
			// ���� ���ư��� �ٸ� ����� ã�� �ʿ䰡 ����  
		}
	}
		
}



int main(void){
	freopen("input.txt", "rt", stdin);
	int i, j;
	int cnt;
	while(true){
		scanf("%d %d", &w, &h);
		if(w==0 && h==0){
			return 0;
		}
		
		for(i=0; i<h; i++){
			for(j=0; j<w; j++){
				scanf("%d", &map[i][j]);
				// �� �ļ��θ��� ����
				// �����͸� �� �־�߸� DFS ���ư� �� ������ Ž���ϴµ�
				// scanf �� ���ÿ� Ž���ϴϱ� ����� ������â ������ ����  
			}
		}
		
		cnt=0;
		
		for(i=0; i<h; i++){
			for(j=0; j<w; j++){
				if(ch[i][j]==0&&map[i][j]==1){
					DFS(i, j); //���� �ش��ϴ� ���� DFS ����
					// ������ ó������ ������ ���� DFS���� �ٸ� ���� ���  
					
					// ���� ���̰� �ƹ��� �� ��·��
					// DFS�� �� ���� ��ȯ�Ǵ� ���� ���� ������ 1�� �߰��Ǵ� ��  
					cnt++;
				}
			}
		}
		
		
		printf("%d\n", cnt);
 
		memset(ch, 0, sizeof(ch));
		memset(map, 0, sizeof(map));
		
	}

	
	

}

