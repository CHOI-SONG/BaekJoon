
pibo = [1,1]

n = (int)(input())

for i in range(n-1):
    pibo.append(pibo[i] + pibo[i+1])


print(pibo[n-1])