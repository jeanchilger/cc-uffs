s = input()
f = open("in.txt", "w")

print("v2.0 raw", file=f)

for x in s:
    print(hex(ord(x))[2:], end=" ", file=f)

print(file=f)    
f.close()
