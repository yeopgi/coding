import sys
n = int(sys.stdin.readline())

sp = 0
my_stack = [0 for i in range (0, 100000 + 1)]
for i in range(n):
    command = sys.stdin.readline().split()
    if command[0] == 'push':
        my_stack[sp] = command[1]
        sp += 1

    elif command[0] == 'pop':
        if 0 == sp :
            print(-1)
            continue

        print(my_stack[sp - 1])
        my_stack[sp - 1] = 0
        sp -= 1

    elif command[0] == 'size': # 크기 조회
        if sp == 0:
            print(0)
            continue

        print(sp)

    elif command[0] == 'empty' : # 크기 조회
        if sp != 0:
            print(0)
            continue

        print(1)

    elif command[0] == 'top' :
        if 0 == sp:
            print(-1)
            continue

        print(my_stack[sp - 1])

