def solve():
    n = int(input())
    tbytes = []
    # origin = []
    num_str = input()
    num_str.strip("\n")
    nums = num_str.split(' ')
    for num in nums:
        num = int(num)
        byte = bin(num)
        # origin.append(byte)
        lentgh = len(byte)
        if(lentgh > 10):
            byte = byte[lentgh-8:lentgh]
        else:
            byte = byte[2:]
        tbytes.append(byte)
    # print(tbytes)
    # print(origin)
    if n == 1:
        if tbytes[0][0] == '0':
            return 1
        else:
            return 0
    else:
        post_byte_head = '10'
        head_head = ""
        for i in range(n):
            head_head += '1'
        head_head += '0'
        head = tbytes[0]
        if head[0:n] != head_head:
            return 0

        for byte in tbytes[1:]:
            if byte[0:1] != post_byte_head:
                return 0


if __name__ == "__main__":
    print(solve(), end='')
