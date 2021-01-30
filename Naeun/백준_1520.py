import sys
sys.setrecursionlimit(10000)

n, m = map(int, input().split())

li = []
ch = [[-1] * m for i in range(n)]

for i in range(n):
    a = list(map(int, input().split()))
    li.append(a)



dx = [1,-1,0,0]
dy = [0,0,1,-1]


def dfs(x,y):


    if x == n-1 and y == m-1:
        return 1
    if ch[x][y] != -1:
        return ch[x][y]

    ch[x][y] = 0

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < m:
            if li[nx][ny] < li[x][y]:
                ch[x][y] += dfs(nx, ny)

    return ch[x][y]

print(dfs(0,0))
