#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	stack<char> s;
	int i=0;
	vector<char> v;
	char input[101];
	scanf("%s", input);
	
	for(i=0; input[i]!='\0'; i++){
		if(inpu                                                                                   t[i]>='A'&&input[i]<='Z') v.push_back(input[i]);
		else{
			switch(input[i]){
				case ')':
					while(!s.empty() && s.top() !='('){
						v.push_back(s.top());
						s.pop();
					}
					s.pop(); // '(' ���ߵ�  
					break;
				case '(':
					s.push(input[i]);
					break;
				case '+':
				case '-':
					while(!s.empty() && s.top()!='('){
						v.push_back(s.top());
						s.pop();
					}
					s.push(input[i]); // �켱���� ���� �� �ְ� �ֱ�  
					break;
				case '*':
				case '/':
					while(!s.empty() && (s.top()=='*' || s.top()=='/')){
						v.push_back(s.top());
						s.pop();
					}
					s.push(input[i]);
					break;
					
			}
		}		
	}
	
	while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }

	for (vector<char>::iterator iter=v.begin(); iter !=v.end(); ++iter){
		cout << *iter;
	}
	
	return 0;
} 
