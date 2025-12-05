load("utils.sage")
load("decompositions.sage")
load("distribution_rlwe.sage")

class GSW:
    def __init__(self , n, q, sigma , B = 2):
        self.n, self.sigma , self.B = n, sigma , B
        f = x^n + 1
        self.l = ceil(log(q, B))
        self.q = B^self.l
        g = Matrix(ZZ, self.l, 1, [B^i for i in range(self.l)])
        I = Matrix.identity(2)
        self.G = I.tensor_product(g) # gadget matrix
        self.Rq = (ZZ.quotient(q) )['x'].quotient(f)
        self.sk = self.keygen()
        self.dist_rlwe = RLWEDistribution(self.sk, n, q, sigma)

    def keygen(self):
        sk = 0
        while 0 == sk:
            sk = Zx([ZZ.random_element(-1, 2) for _ in range(self.n)])
        return sk

    def enc(self , m):
        Rq, l, sk = self.Rq, self.l, self.sk
        C = Matrix(Rq, 2*l, 2)
        for i in range(2*l):
            C[i] = self.dist_rlwe.sample()
        C += m * self.G
        return C

    def dec(self , C):
        B, l, q, sk = self.B, self.l, self.q, self.sk
        a = C[2*l - 1, 0]
        b = C[2*l - 1, 1] # == a*sk + e + (q/B) * m
        noisy_m = Zx((b - a*sk).lift())
        rounded_m = round_poly(B * noisy_m / q)
        return sym_mod_poly(rounded_m , B)
    
    def add(self , C0, C1):
        C_add = C0 + C1
        return C_add

    def inv_g_row_ciphertex(self , c):
        B, l, n, q = self.B, self.l, self.n, self.q
        a, b = c[0], c[1]
        res = vector(self.Rq, [0] * 2 * l)
        res[0 : l] = inv_g_poly(a, B, q, n)
        res[l : 2*l] = inv_g_poly(b, B, q, n)
        return res

    def mult(self, c0, c1):
        result = Matrix(self.Rq, 2*self.l, 2)
        for i in range(2*self.l):
            decomp = self.inv_g_row_ciphertex(c0[i])
            prod_in_Rq = decomp*c1
            result[i] = prod_in_Rq
        return result

    def not_gate(self , C):
        return C + self.G

    def get_noise(self , C, msg):
        l, sk = self.l, self.sk
        C -= msg * self.G
        a = vector(C[:, 0])
        b = vector(C[:, 1]) # == a*sk + e (mod q)
        e = b - a*sk
        e = sym_mod_vec(e, self.q) # definida em utils.sage
        norm_e = infinity_norm_vec(e) # definida em utils.sage

        if norm_e == 0: # log de zero não está definido
            return -1
        return log(norm_e , 2).n()