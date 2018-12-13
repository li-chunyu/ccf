'''
@Description: 20180910
@Author: lichunyu
@Date: 2018-10-25 11:28:33
@LastEditTime: 2018-12-13 21:35:33
@LastEditors: Please set LastEditors
'''
n = int(input().rstrip())
h_interval = []
w_interval = []
for i in range(0, n):
    interval = [int(t) for t in input().rstrip().split(' ')]
    h_interval.append(interval)
for i in range(0, n):
    interval = [int(t) for t in input().rstrip().split(' ')]
    w_interval.append(interval)

re = 0
for h_i in h_interval:
    for w_i in w_interval:
        begin = max(h_i[0], w_i[0])
        end = min(h_i[1], w_i[1])
        t = end - begin
        if t > 0:
            re = re + t 
print(re)