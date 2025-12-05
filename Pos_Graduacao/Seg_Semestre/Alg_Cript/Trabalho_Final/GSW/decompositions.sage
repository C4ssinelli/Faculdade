def inv_g_ZZ(a, B, q):
    a = sym_mod(ZZ(a), q) # definida em utils.sage
    l = ceil(log(q, B))
    return vector(a.digits(base=B, padto=l))

def inv_g_poly(a, B, q, n):
    l = ceil(log(q, B))
    result = vector(Zx, [0] * l)
    pow_x = 1
    for i in range(n):
        result += pow_x * inv_g_ZZ(a[i], B, q)
        pow_x *= x
    return result