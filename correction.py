a,b,c=input('').split(' ')
a=int(a)
b=int(b)
c=int(c)
if a>=b and b>=c:
    t=a
    a=c
    c=t
    print(a,b,c)
elif a>=c and c>=b:
    t=a
    a=c
    c=t
    t=a
    a=b
    b=t
    print(a,b,c)
elif b>=c and c>=a:
    t=b
    b=c
    t=c
    print(a,b,c)
elif b>=a and a>=c:
    t=a
    a=c
    c=t
    t=b
    b=c
    c=t
    print(a,b,c)
elif c>=a and a>=b:
    t=a
    a=b
    b=t
    print(a,b,c)
else:
    print('heyyy')
