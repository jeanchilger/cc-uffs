import brailledots as bd
import dotsBool as bb

s = input().upper()
f = open("in.txt", "w")

print("v2.0 raw", file=f)

for x in s:
    inp = list(bin(ord(x))[4:])
    print(inp)

    #braille_ascii = "10"
    braille_ascii = ""
    braille_ascii += str(int(bb.p1(*tuple(map(int, inp)))))
    braille_ascii += str(int(bb.p2(*tuple(map(int, inp)))))
    braille_ascii += str(int(bb.p3(*tuple(map(int, inp)))))
    braille_ascii += str(int(bb.p4(*tuple(map(int, inp)))))
    braille_ascii += str(int(bb.p5(*tuple(map(int, inp)))))
    braille_ascii += str(int(bb.p6(*tuple(map(int, inp)))))

    hex_br = hex(int(braille_ascii, 2))[2:]
    print(x, ": ", braille_ascii)
    print(hex_br, end=" ", file=f)
    print()

print(file=f)
f.close()
