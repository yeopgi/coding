yyyy = int(input())

if (yyyy % 4 == 0):
    if (yyyy % 100 != 0 or yyyy%400 == 0):
        print(1)
        exit()

print(0)