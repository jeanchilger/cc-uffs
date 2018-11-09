def p1(*args):
    c, d, e, f, g = args
    return ((not(d) and not(e) and not(f)) or (not(d) and f and not(g)) or (not(c) and e) or (not(c) and not(f) and not(g)) or (not(c) and f and g) or (c and d) or (not(d) and e and not(f) and g))

def p2(*args):
    c, d, e, f, g = args
    return ((not(d) and not(f) and not(g)) or (d and not(f) and g) or (c and not(e) and not(f)) or (not(d) and f and g) or (not(c) and not(d) and f and g) or (not(c) and not(d) and f and e) or (not(c) and d and f and not(g)))

#def p3(*args):
#    c, d, e, f, g = args
#    return ((not(c) and d and not(e) and not(f)) or (not(c) and not(g) and not(e)) or (not(d) and e and f) or (not(d) and not(e) and f) or (c and not(d) and not(e)) or (c and not(d) and not(f) and not(g)) or (not(c) and not(g) and not(e)))

def p3(*args):
    c, d, e, f, g = args
    return ((not(c) and not(e) and not(f) and d) or (not(c) and not(e) and f and not(g)) or (not(d) and not(e) and c) or (c and not(d) and not(g) and not(f)) or (f and not(d) and e) or (not(c) and d and not(f) and not(g)))

def p4(*args):
    c, d, e, f, g = args
    return ((d and f and not(g)) or (e and f and g) or (not(d) and e and not(f) and not(g)) or (not(c) and not(e) and not(f) and not(g)) or (not(c) and not(d) and e and g) or (not(e) and c and not(f) and g) or (c and not(e) and f and not(g)))

def p5(*args):
    c, d, e, f, g = args
    return ((d and e) or (c and not(g)) or (c and not(f)) or (c and not(e)) or (d and f and g))

def p6(*args):
    c, d, e, f, g = args
    return ((not(c) and not(d) and not(e) and not(f) and not(g)) or (c and d) or (c and e and g) or (c and e and f))
