import brailledots

s = input().upper()
f = open("in.txt", "w")

print("v2.0 raw", file=f)

for x in s:
    print(hex(int(brailledots.dots[hex(ord(x)).upper()[2:]], 2))[2:], end=" ", file=f)

print(file=f)
f.close()
