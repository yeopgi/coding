from collections import deque

n, m = map(int, input().split())
target_num = list(map(int, input().split()))
if 1 == n:
    print(0)

arr = deque([i for i in range(1, n+1)])
total_cnt = 0
for i in target_num:
    arr_len = len(arr)
    while (True):
        if (arr[0] == i):
            #print(0)
            #print(*arr)
            arr.popleft()
            break
        else:
            if (arr.index(i) < len(arr) / 2):
                while(arr[0] != i):
                    arr.append(arr.popleft())
                    total_cnt += 1
            else:
                while(arr[0] != i):
                    arr.appendleft(arr.pop())
                    total_cnt += 1

print(total_cnt)