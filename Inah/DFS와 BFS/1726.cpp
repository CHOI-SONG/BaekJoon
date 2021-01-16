#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
struct pos {
    int x, y;
};
 
struct robot {
    pos p;
    int dir;
    int cnt;
};
 
int di[] = { -1,0,1,0 };
int dj[] = { 0,1,0,-1 };
 
int M, N;
int map[100][100];
bool visited[100][100][4];
vector<robot> v;
int res;
 
bool inner(int x, int y) {
    if (x < 0 || y < 0 || x >= M || y >= N) {
        return false;
    }
    return true;
}
 
void bfs(robot str) {
    queue<robot> q;
    q.push(str);
    visited[str.p.x][str.p.y][str.dir] = true;
 
    while (!q.empty()) {
        robot cur = q.front();
        q.pop();
 
        //목적지 도달 - 종료
        if (cur.p.x == v[1].p.x && cur.p.y == v[1].p.y && cur.dir == v[1].dir) {
            res = cur.cnt;
            return;
        }
 
        //명령 Go
        for (int i = 1; i <= 3; i++) {
            robot nxt = cur;
            nxt.p.x += di[nxt.dir] * i;
            nxt.p.y += dj[nxt.dir] * i;
            
            //한칸,두칸,세칸 가면서 범위를 넘어가거나 벽을 만날 경우, 다음 칸은 할 필요X 
            if (!inner(nxt.p.x, nxt.p.y)) {
                break;
            }
            if (map[nxt.p.x][nxt.p.y] == 1) {
                break;
            }
 
            if (map[nxt.p.x][nxt.p.y] == 0 && !visited[nxt.p.x][nxt.p.y][nxt.dir]) {
                nxt.cnt++;
                q.push(nxt);
                visited[nxt.p.x][nxt.p.y][nxt.dir] = true;
            }
        }
        
        //명령 Turn dir
        for (int i = 0; i < 4; i++) {
            robot nxt = cur;
 
            //2로 나눈 나머지가 다른 방향만 탐색(왼쪽, 오른쪽)
            if (i % 2 != nxt.dir % 2) {
                nxt.dir = i;
                if (!visited[nxt.p.x][nxt.p.y][nxt.dir]) {
                    nxt.cnt++;
                    q.push(nxt);
                    visited[nxt.p.x][nxt.p.y][nxt.dir] = true;
                }
            }
        }
    }
}
 
int main() {
 
    //입력
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        robot tmp = { x,y,dir,0 };
        v.push_back(tmp);
    }
 
    //입력값 조정
    //좌표 - 1(배열과 맞추기 위해), 방향 북동남서(왼쪽 오른쪽 쉽게 하기 위해)
    for (int i = 0; i < 2; i++) {
        v[i].p.x -= 1;
        v[i].p.y -= 1;
        if (v[i].dir == 1) {
            v[i].dir = 1;
        }
        else if (v[i].dir == 2) {
            v[i].dir = 3;
        }
        else if (v[i].dir == 3) {
            v[i].dir = 2;
        }
        else {
            v[i].dir = 0;
        }
    }
 
    //로봇 처음 위치에서 탐색 시작
    bfs(v[0]);
 
    //출력
    cout << res;
}
