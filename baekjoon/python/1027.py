N = int(input())
buildings = list(map(int, input().split()))


def caculate_gradient(x1, y1, x2, y2):
    gradient = (y2 - y1) / (x2 - x1)
    return gradient


def retrieve_right(standard_x_idx):
    current_idx = standard_x_idx + 1
    max_gradient = None
    see_able = 0
    while current_idx <= N - 1:
        ret = caculate_gradient(standard_x_idx, buildings[standard_x_idx],
                                current_idx, buildings[current_idx])
        if None == max_gradient or max_gradient < ret:
            see_able += 1
            max_gradient = ret

        current_idx += 1

    return see_able


def retrieve_left(standard_x_idx):
    current_idx = standard_x_idx - 1
    min_gradient = None
    see_able = 0
    while current_idx >= 0:
        ret = caculate_gradient(standard_x_idx, buildings[standard_x_idx],
                                current_idx, buildings[current_idx])
        if None == min_gradient or min_gradient > ret:
            see_able += 1
            min_gradient = ret

        current_idx -= 1

    return see_able

max_see_able = 0

for i in range(N):
    ret = retrieve_left(i) + retrieve_right(i)

    if max_see_able < ret:
        max_see_able = ret

print(max_see_able)
