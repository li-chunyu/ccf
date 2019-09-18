from functools import cmp_to_key

def to_stdaddr(ippre):
    ippre = ippre.rstrip().split('/')
    ip = []
    if len(ippre) == 1:# 省略
        ip = ippre[0].split('.')
        netmask = len(ip) * 8
        for _ in range(4-len(ip)):
            ip.append('0')
        ip.append(str(netmask))
    else:
        netmask = ippre[1]
        ip = ippre[0].split('.')
        for _ in range(4-len(ip)):
            ip.append('0')
        ip.append(str(netmask))
    addr = 0
    for i in range(4):
        addr += int(ip[i]) * pow(256, 3 - i)
    return [addr, int(ip[4])]

def ippre_cmp(pre1, pre2):
    if pre1[0] != pre2[0]:
        return pre1[0] - pre2[0]
    else:
        return pre1[1] - [pre2][1]

n = int(input().rstrip())
pre_list = []
for _ in range(n):
    ippre = input().rstrip()
    pre_list.append(to_stdaddr(ippre))
pre_list = sorted(pre_list, key=cmp_to_key(ippre_cmp))

cur = 0
nxt = cur + 1
while cur != len(pre_list)-1:
    if pre_list[cur][0] == -1:
        cur += 1
        nxt = cur + 1
        continue
    if nxt == len(pre_list):
        cur += 1
        nxt = cur + 1
        continue
    if pre_list[cur][1] > pre_list[nxt][1]:
        cur += 1
        nxt = cur + 1
        continue
    cur_mask = int('1'*pre_list[cur][1] + '0'*(32-pre_list[cur][1]), base=2)
    if pre_list[nxt][0]&cur_mask == pre_list[cur][0]&cur_mask:
        pre_list[nxt][0] = -1
        nxt += 1
    else:
        cur += 1
        nxt = cur + 1

# print(pre_list)
cur = 0
nxt = cur + 1
while cur != len(pre_list)-1:
    if pre_list[cur][0] == -1:
        cur += 1
        nxt = cur + 1
        continue
    if nxt == len(pre_list):
        cur += 1
        nxt = cur + 1
        continue