n = (int)(input())

li = []
ch = [0] * n
ans = []
cnt = 0

for i in range(n):
    str = input()
    li.append(str)




q = []

for k in range(n):

    cnt = 0
    ch = [0] * n
    ch[k] = 1

    for i in range(n):
        if li[k][i] == 'Y' and ch[i] == 0:
            ch[i] = 1
            q.append(i)
            cnt += 1

    while q:
        x = q.pop()
        for i in range(n):
            if li[x][i] == 'Y' and ch[i] == 0:
                ch[i] = 1
                cnt += 1

    ans.append(cnt)

print(max(ans))