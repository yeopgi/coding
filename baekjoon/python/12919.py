import sys

s = sys.stdin.readline().strip()
t= sys.stdin.readline().strip()

def Run(t):
    global s
    if (s == t):
        print(1)
        exit(0)

    if (len(t) < 1):
        return 0

    if (t[-1] == 'A'):
        Run(t[:-1])
    
    if(t[0] == 'B'):
        Run(t[1:][::-1])

Run(t)
print(0)
