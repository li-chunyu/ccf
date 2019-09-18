block_size = 4 # Bytes
n, s, l = list(map(int, input().rstrip().split()))
nloss = n - l
exist_disk = []
raid = {}
disksize = 0 # blocks
for _ in range(l):
    disk_num, disk_data = input().rstrip().split()
    disk_num = int(disk_num)
    exist_disk.append(disk_num)
    disksize = int(len(disk_data) / 8)
    raid[disk_num] = disk_data
m = int(input().rstrip())
total_vol = (n-1) * disksize # blocks
for _ in range(m):
    nblock = int(input().rstrip())
    if nblock > total_vol-1:
        print('-')
        continue
    nstrid = nblock // s
    nblock_in_strid = nblock % s
    k = nstrid // (n-1)
    xor_disk = (n-1) - (k%n)
    ndisk = (xor_disk+1+(nstrid - (n-1)*k)) % n
    if ndisk in exist_disk:
        data = raid[ndisk]
        block_on_disk = k * s + nblock_in_strid
        q_data = data[block_on_disk*2*block_size : (block_on_disk+1)*2*block_size]
        print(q_data)
        continue
    else:
        if nloss > 1:
            print('-')
            continue
        else:
            # get data from xor data.
            # xor_data = raid[xor_disk][k*s*block_size*2: (k+1)*s*block_size*2]
            block_on_disk = k * s + nblock_in_strid
            xor_data = raid[xor_disk][block_on_disk*2*block_size: (block_on_disk+1)*2*block_size]
            # print(xor_data)
            xor_data = int(xor_data, base=16)
            for d in range(n):
                if d == ndisk or d == xor_disk:
                    continue
                d_data = raid[d][block_on_disk*2*block_size: (block_on_disk+1)*2*block_size]
                # print(d_data)
                d_data = int(d_data, base=16)
                xor_data = xor_data ^ d_data
            xor_data = hex(xor_data).upper().split('X')[1]
            print(xor_data)
            continue