from collections import deque

n, m = map(int, input().split())
target_num = list(map(int, input().split()))
if 1 == n:
    print(0)

arr = deque([i for i in range(1, n+1)])
total_cnt = 0
for i in range(0, m):
    arr_len = len(arr)
    for j in range(0, arr_len):
        if target_num[i] == arr[j]:
            target_idx = j
            ##print(target_idx)
            if (target_idx == 0):
                #print(0)
                #print(*arr)
                arr.popleft()
                break

            else:
                if (target_idx > (arr_len / 2)):
                    rotation_cnt = arr_len - target_idx
                    #print(1)
                    #print(rotation_cnt)
                    total_cnt = total_cnt + rotation_cnt
                    while (rotation_cnt):
                        arr.rotate(1)
                        rotation_cnt = rotation_cnt - 1
                        #print(*arr)

                else:
                    #print(2)
                    rotation_cnt = target_idx
                    
                    total_cnt = total_cnt + rotation_cnt
                    #print(rotation_cnt)
                    while (rotation_cnt):
                        arr.rotate(-1)
                        rotation_cnt = rotation_cnt - 1
                        #print(*arr)

                arr.popleft()
                #print(*arr)
                break

print(total_cnt)






