import sys

n = int(sys.stdin.readline())
state = ["제로"] + list(map(int, sys.stdin.readline().split()))
p = int(sys.stdin.readline())

# 반복문을 통해 스위치 상태를 변경
for i in range(p):
    # 성별, 학생이 받은 수
    sex, idx = map(int, sys.stdin.readline().split())

    # 남학생
    if sex == 1:
        plus = idx
        while plus <= n:
            state[plus] = abs(state[plus] - 1)
            plus += idx

    # 여학생
    else:
        total = min(n + 1 - idx, idx)
        state[idx] = abs(state[idx] - 1)

        for j in range(total):
            if state[idx - j] == state[idx + j]:
                state[idx - j] = abs(state[idx - j] - 1)
                state[idx + j] = abs(state[idx + j] - 1)

            else:
                break

# 20개씩 출력
for i in range(1, n + 1):
    print(state[i], end=" ")

    if i % 20 == 0:
        print("")
