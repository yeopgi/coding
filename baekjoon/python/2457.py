import sys
T = int(sys.stdin.readline().strip())
days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
sums = [0] * len(days)


def md_to_int(month, day):
    return sums[month] - (days[month] - day)


for i in range(1, len(days)):
    if i == 1:
        sums[i] = days[i]
    else:
        sums[i] = days[i] + sums[i-1]

curr = md_to_int(3, 1)
tot = 0
myarr = []
while (T > 0):
    month1, day1, month2, day2 = map(int, sys.stdin.readline().strip().split())
    myarr.append([md_to_int(month1, day1), md_to_int(month2, day2)])
    T -= 1

while (curr <= 334):
    nxt_t = curr
    for i in range(len(myarr)):
        if (myarr[i][0] <= curr and myarr[i][1] > nxt_t):
            nxt_t = myarr[i][1]

    if (nxt_t == curr):
        print(0)
        exit(0)

    tot += 1
    curr = nxt_t
print(tot)