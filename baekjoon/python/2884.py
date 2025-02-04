import sys

h,m = map(int, input().split())
# if h ==0

if (m < 45):
    h = h -1
    if (h < 0):
        h = 23
        
    m = m + 60
    m = m - 45
    print(h,m )

else:
    print(h,m - 45)

