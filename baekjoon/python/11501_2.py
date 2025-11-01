import sys
T = int(sys.stdin.readline().strip())
while (T > 0):
    tot=0
    N = int(sys.stdin.readline().strip())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    T -= 1
    end = len(arr)-1
    max_val = 0
    while (end >=0):
        # curr_num = arr[end]
        if max_val > arr[end]:
            tot += max_val - arr[end]
        elif max_val < arr[end]:
            max_val = arr[end]
        end -= 1

    print(tot)