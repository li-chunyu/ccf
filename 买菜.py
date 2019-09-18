import sys

# sys.stdin = open('test.txt', 'r')
durs = []
n = int(input().rstrip())
for _ in range(2*n):
    durs.append(list(map(int, input().rstrip().split())))
durs = sorted(durs, key=lambda dur: dur[0])
ret = 0
for i in range(len(durs)):
    for j in range(i+1, len(durs)):
        t = min(durs[i][1], durs[j][1]) - max(durs[i][0], durs[j][0])
        if t < 0:
            break
        else:
            print(durs[i][0], durs[i][1])
            print(durs[j][0], durs[j][1])
            print()
            ret += t

print(ret)
