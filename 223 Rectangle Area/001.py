class Solution:
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        if self.uncover(A, B, C, D, E, F, G, H):
            return self.calcS(A, B, C, D) + self.calcS(E, F, G, H)
        ans = self.calcS(A, B, C, D)
        if A > E:
            ans += self.calcS(E, F, A, H)
            E = A
        if C < G:
            ans += self.calcS(C, F, G, H)
            G = C
        if B > F:
            ans += self.calcS(E, F, G, B)
            F = B
        if D < H:
            ans += self.calcS(E, D, G, H)
            H = D
        return ans
    def calcS(self, xa, ya, xb, yb):
        return (xb - xa) * (yb - ya)
    def uncover(self, xa, ya, xb, yb, xc, yc, xd, yd):
        if ya >= yd:
            return True
        if yb <= yc:
            return True
        if xa >= xd:
            return True
        if xb <=xc:
            return True
        return False