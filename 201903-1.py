import math
def num2str(num):
    i, _ = math.modf(num)
    if i == 0.0:
        return str(int(num))
    else:
        return str(num)
    
        
n = int(input())
l = list(map(int, input().rstrip().split()))
l.sort()
ret = []
ret.append(max(l))
ret.append(min(l))
if (len(l) % 2) == 0:
    ret.append((l[len(l)//2] + l[len(l)//2-1])/2)
else:
    ret.append(l[len(l)//2])
ret.sort(reverse=True)
print(" ".join(list(map(num2str, ret))))