a = 4
b = 2 ** a
for i in range(b):
    result = i ^ (i >> 1)
    print(f"{bin(result)[2:].zfill(a)}")