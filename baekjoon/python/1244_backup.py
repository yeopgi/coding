switch_cnt = int(input())
switch_status = ["제로"] + list(map(int, input().split()))
student_status = []
student_cnt = int(input())

for i in range(student_cnt):
    student_status.append(list(map(int, input().split())))

for i in student_status:
    if i[0] == 1:
        for j in range(1, switch_cnt + 1):
            if i[1] * j > switch_cnt:
                break

            switch_status[(i[1] * j)] = int(not switch_status[(i[1] * j)])

    else:
        switch_status[i[1]] = int(not switch_status[i[1]])
        for j in range(1, switch_cnt + 1):
            if i[1] - j < 0 or i[1] + j > switch_cnt:
                break
            else:
                if switch_status[(i[1] - j)] == switch_status[(i[1] + j)]:
                    switch_status[(i[1] - j)] = int(not switch_status[(i[1] - j)])
                    switch_status[(i[1] + j)] = int(not switch_status[(i[1] + j)])
                else:
                    break

for i in range(1, switch_cnt + 1):
    print(switch_status[i], end=" ")
    if (i % 20) == 0:
        print("")



