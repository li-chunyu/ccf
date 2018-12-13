input1 = input()
input2 = input()

n = int(input1)
first_day_price = [int(i) for i in input2.rstrip().split(' ')]
sec_day_price = [0 for i in range(0, n)]
for i in range(0, n):
    if i == 0:
        sec_day_price[0] = (first_day_price[i + 1] + first_day_price[0]) // 2
    elif i == n-1:
        sec_day_price[n-1] = (first_day_price[n-2] + first_day_price[n-1]) // 2
    else:
        sec_day_price[i] = (first_day_price[i-1] + first_day_price[i+1] + first_day_price[i]) // 3
print(' '.join([str(i) for i in sec_day_price]))

