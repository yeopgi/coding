N, M = tuple(map(int, input().split()))

table = []
for _ in range(N):
    table.append(input())

K = int(input())
max_cnt = 0

for col in range(N):
    zero_cnt = 0
    for i in table[col]:
        if '0' == i:
            zero_cnt += 1

    col_light_cnt = 0
    if zero_cnt <= K and zero_cnt % 2 == K % 2:
        for col2 in range(N):
            if table[col] == table[col2]:
                col_light_cnt += 1

    max_cnt = max(max_cnt, col_light_cnt)

print(max_cnt)

# 출처 : https://yhkim4504.tistory.com/11
