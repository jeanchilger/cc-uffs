import brailledots

f = open("out.txt", "r")
s = f.read()

for p in range(9, len(s), 3):
    print(chr(int("0x" + s[p:p+2], 16)), sep="")

f.close()
