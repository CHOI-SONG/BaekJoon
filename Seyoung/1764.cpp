#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, i, j, cnt=0;
	string name;
	scanf("%d %d", &n, &m);
	vector<string> nVector;
	vector<string> mVector;
	
	for (i=0; i<n; i++){
		cin>>name;
		nVector.push_back(name);
	}
	
	sort(nVector.begin(), nVector.end()); // n���� �迭�� �����Ѵ� 
	
	// �޾Ƶ��Ӱ� ���ÿ� ��ġ�ϸ鼭 �ð��� ���δ� 
	// ������ ����? ��� ����~  
	
	for(i=0; i<m; i++){
		cin>>name; 
		if(binary_search(nVector.begin(), nVector.end(), name)){
			mVector.push_back(name);
			cnt++;
		}
	}
	// ����Ž���� ������ �Ǿ� �ִٴ� ���� �Ͽ� ã�´�
	// ������, ����, ã�� �� 3���� �Ű������� �ҵ�?!  
	
	sort(mVector.begin(), mVector.end());
	
	// getline�Լ��� �� ��� �ؽ�Ʈ�� �о���̴� �� ���ϴ°�?
	
	cout << cnt <<endl; //�����ɷ��� ���� ����鼭..  
	for(i=0; i<mVector.size(); i++){
		cout << mVector[i] << endl;
	}
	
	return 0;
} 
