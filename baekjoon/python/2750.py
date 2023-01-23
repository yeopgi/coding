N = int(input())
arr = [0 for i in range(N)]

for i in range(0, N):
    num = int(input())
    arr[i] = num

arr.sort()
for i in range(N):

    print(arr[i])