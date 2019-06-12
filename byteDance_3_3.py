ips = input()
L = len(ips)
if(L <= 4):
    print(1)
else:
    count = 0
    out_list = []

    def dfs(dot_num, in_buffer):
        global count, out_list
        if(dot_num == -1):
            if in_buffer == '':
                x = True
                for num in out_list:
                    if num > 255:
                        x = False
                        break
                if x:
                    count += 1
            return
        else:
            l = len(in_buffer)
            for i in range(l-dot_num):
                anum = int(in_buffer[0:i+1])
                out_list.append(anum)
                dfs(dot_num-1, in_buffer[i+1:])
                out_list = out_list[:-1]
                if anum == 0:
                    return
    dfs(3, ips)
    print(count)
