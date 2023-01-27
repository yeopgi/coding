N, M = map(int, input().split())
my_vector = list(map(int, input().split()))
ans = [0 for i in range(0, 10000 + 1)]


def is_right():
    for i in range(0, M - 1):
        if (ans[i] <= ans[i + 1]):
            return True

    return False


def Run(start_idx, depth):
    ans[depth] = my_vector[start_idx]
    if (depth == M - 1):
        if is_right() == True:
            for i in range(0, M):
                print(ans[i], end=' ')

            print('')

        return

    for i in range(0, len(my_vector)):
        Run(i, depth + 1)


my_vector.sort()
if (M == 1):
    for i in range(0, len(my_vector)):
        print(my_vector[i])
else:
    for i in range(0, N):
        Run(i, 0)
