import sys

cnt = int(input())


str_list = [[] for i in range(0, 51)]

for i in range(cnt):
    input_str = input()
    str_len = len(input_str)
    if input_str in str_list[str_len]:
        continue
    str_list[str_len].append(input_str)

# for i in range(1,51):
#     set(str_list[i])

for i in range(1,51):
    str_list[i].sort()
    # sorted(str_list[i])
#str_list[i].sort(key=len)
# print()
for i in range(1,51):
    if len(str_list[i]) > 0:
        for j in range(len(str_list[i])):
            print(str_list[i][j])