import sys

while (True):
    input_str = input()
    str_len = len(input_str)

    if (input_str == '0'):
        break

    if (str_len == 1):
        print("yes")
        continue

    temp_val = False
    for i in range(0, str_len // 2):
        if (input_str[i] != input_str[str_len - (i + 1)]):
            print("no")
            temp_val = True
            break
    if temp_val is False:
        print("yes")

    # if str_len % 2 is 0:
        
    # else:

