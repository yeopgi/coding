import sys
temp = 1
for i in range(3):
    input_num = int(input())
    temp *= input_num

temp = str(temp)
# print(temp)
for i in range(0, 10):
    i_chr = str(i)
    # print(str(i))
    i_cnt = 0
    count = temp.count(i_chr)
    # for j in range(len(temp)):
    #     if (i_chr == temp[j]):
    #         i_cnt +=1

    print(count)