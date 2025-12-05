load("utils.sage")
load("distribution_acd.sage")

class DGHV:
    def __init__(self , gamma , eta, rho, t = 2**20, p = 1):
        assert(gamma > eta)
        assert(eta > rho)
        if 1 == p:
            p = random_prime(2^eta, lbound=2^(eta - 1))
        else:
            # if p is given , it must have eta bits
            assert(eta - 1 <= p.nbits() <= eta)
        self.gamma = gamma
        self.eta = eta
        self.rho = rho
        self.t = t
        self.p = p
        self.x0 = p * sample_q(gamma , eta) #+ self.sample_r()
        self.Zp = ZZ.quotient(p)
        self.Zx0 = ZZ.quotient(self.x0)
        
    def enc(self , m):
        q = sample_q(self.gamma , self.eta)
        r = sample_r(self.rho)
        c = self.p*q + self.t * r + m
        c %= self.x0
        return c

    def dec(self , c):
        noisy_msg = sym_mod(c, self.p) # == t * r + msg
        return noisy_msg % self.t

    def not_gate(self , c):
        return (1 - c) % self.x0

    def add(self , c1, c2):
        return (c1 + c2) % self.x0

    def mult(self , c1, c2):
        return c1 * c2 % self.x0

    # ===========================================================
# Função de ruído para DGHV
# ===========================================================

def get_noise_dghv(dghv, c, m):
    """
    Retorna o ruído absoluto |t*r| de um criptograma DGHV.
    Calcula noise = (c mod p) - m.
    """
    noisy_msg = sym_mod(c, dghv.p)   # = t*r + m
    noise = noisy_msg - m            # = t*r
    return abs(int(noise))


def ruido_norm(noise_abs, p):
    return float(noise_abs) / float(p/2)