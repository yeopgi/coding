import sys
n = int(sys.stdin.readline())

back = 0
my_q = [0 for i in range (0, 100000 + 1)]
for i in range(n):
    command = sys.stdin.readline().split()
    if command[0] == 'push':
        my_q[back] = command[1]
        back +=1

    elif command[0] == 'pop':
        if 0 == back :
            print(-1)
            continue

        print(my_q[0])
        for i in range(0, back):
            if back - 1 == i:
                continue

            my_q[i] = my_q[i + 1]

        back -= 1

    elif command[0] == 'size':
        print(back)

    elif command[0] == 'empty' :
        if back != 0:
            print(0)
            continue

        print(1)

    elif command[0] == 'front' :
        if 0 == back:
            print(-1)
            continue

        print(my_q[0])

    elif command[0] == 'back' :
        if 0 == back:
            print(-1)
            continue

        print(my_q[back - 1])

