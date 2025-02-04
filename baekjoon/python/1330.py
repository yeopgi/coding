import sys

aaa, bbb = map(int, sys.stdin.readline().split())

if aaa > bbb:
    print('>')
elif aaa < bbb:
    print('<')
else:
    print('==')
