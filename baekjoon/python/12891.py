import sys
from collections import defaultdict
s, p = map(int, sys.stdin.readline().split())
alphabet_cnt = defaultdict(int)
dna = sys.stdin.readline().strip()
a_cnt, c_cnt, g_cnt, t_cnt = map(int, sys.stdin.readline().split())
# dna = sys.stdin.readline()
# dna = input()
# print(dna)
ans = 0
alphabet_cnt['A'] = 0
alphabet_cnt['C'] = 0
alphabet_cnt['G'] = 0
alphabet_cnt['T'] = 0
checkSecret = 0


def my_add(c):
    global checkSecret, a_cnt, c_cnt, g_cnt, t_cnt, alphabet_cnt
    if c == 'A':
        alphabet_cnt['A'] += 1
        if alphabet_cnt['A'] == a_cnt:
            checkSecret += 1
    elif c == 'C':
        alphabet_cnt['C'] += 1
        if alphabet_cnt['C'] == c_cnt:
            checkSecret += 1
    elif c == 'G':
        alphabet_cnt['G'] += 1
        if alphabet_cnt['G'] == g_cnt:
            checkSecret += 1
    elif c == 'T':
        alphabet_cnt['T'] += 1
        if alphabet_cnt['T'] == t_cnt:
            checkSecret += 1


def my_remove(c):
    global checkSecret, a_cnt, c_cnt, g_cnt, t_cnt, alphabet_cnt
    if c == 'A':
        if alphabet_cnt['A'] == a_cnt:
            checkSecret -= 1
        alphabet_cnt['A'] -= 1
    elif c == 'C':
        if alphabet_cnt['C'] == c_cnt:
            checkSecret -= 1
        alphabet_cnt['C'] -= 1

    elif c == 'G':
        if alphabet_cnt['G'] == g_cnt:
            checkSecret -= 1
        alphabet_cnt['G'] -= 1

    elif c == 'T':
        if alphabet_cnt['T'] == t_cnt:
            checkSecret -= 1
        alphabet_cnt['T'] -= 1

if a_cnt ==0:
    checkSecret += 1
if c_cnt ==0:
    checkSecret += 1        
if g_cnt ==0:
    checkSecret += 1
if t_cnt ==0:
    checkSecret += 1

for i in range(0, p):
    my_add(dna[i])
# print(alphabet_cnt)

if checkSecret == 4:
    ans += 1

for i in range(p, s):
    j = i - p
    my_add(dna[i])
    my_remove(dna[j])
    # print(alphabet_cnt)
    if checkSecret == 4:
        ans += 1
print(ans)
