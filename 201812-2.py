r, y, g = map(int, input().rstrip().split())
rot = r + y +g
n = int(input().rstrip())
# print(n)
total_wait_time = 0
for i in range(n):
    k, t = map(int, input().rstrip().split())
    if k == 0:
        total_wait_time += t
        continue
    elif k == 1:
        rest = (total_wait_time + r - t) % rot
    elif k == 2:
        rest = (total_wait_time + y - t + r) % rot
    elif k == 3:
        rest = (total_wait_time + g - t + y + r) % rot
    if rest >=0 and rest < r:
        total_wait_time += r - rest + y
    elif rest >= r and rest < r + y:
        total_wait_time += r + y - rest
    elif rest >= r + y and rest < r + y + g:
        continue
print(total_wait_time)
