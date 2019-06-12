lsub_char = []
str = input()
max_count = 0
count = 0
for char in str:
    if char not in lsub_char:
        lsub_char += char
        count += 1
    else:
        if count > max_count:
            max_count = count
        lsub_char = [char]
        count = 1
if max_count < count:
    max_count = count
print(max_count, end='')
