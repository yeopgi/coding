import sys
pos = []
neg = []
N = int(sys.stdin.readline().strip())
zero_cnt = 0
tot = 0
while (N > 0):
    input_num = int(sys.stdin.readline().strip())
    if input_num > 1:
        pos.append(input_num)
    elif input_num <= 0:
        neg.append(input_num)
    else:
        tot += input_num
    N -= 1
pos.sort(reverse=True)
neg.sort()
# print(*pos)
for i in range(0, len(pos), 2):
    if i + 1 >= len(pos):  # 마지막 원소가 홀수개인 경우
        tot += pos[i]
        break
    # 짝수개인 경우
    tot += pos[i] * pos[i+1]

for i in range(0, len(neg), 2):
    if i + 1 >= len(neg):
        tot += neg[i]
        continue
    # 짝수개인 경우

    tot += neg[i] * neg[i+1]


print(tot)
