import sys

N = int(input())
INF = sys.maxsize
list = [[INF] * (N+1) for _ in range(N+1)]
for i in range(1, N + 1):
    for j in range(1, N + 1):
        if i == j :
            list[i][j] = 0

while True:
    src, dst = map(int, input().split())
    if src == -1 and dst == -1:
        break

    list[src][dst] = 1
    list[dst][src] = 1

for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if list[i][j] > list[i][k] + list[k][j]:
                list[i][j] = list[i][k] + list[k][j]

second_list=[]
min_score = INF
for i in range(1, N + 1):
    min_score = min(min_score, max(list[i][1:]))

    # min_score와 일치하는 인덱스 찾기
    second_list = []
    for i in range(1, N + 1):
        if min_score == max(list[i][1:]):
            second_list.append(i)
    second_list.sort()

print(min_score, len(second_list))
print(" ".join(map(str, second_list)))


