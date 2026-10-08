class Solution:
    def reverseBits(self, n: int) -> int:
        # binary = []
        # for i in range(32):
        #     binary.append(n & 1)
        #     n >>= 1
        # res = int("".join(map(str, binary)), 2)
        # return res
        res = 0
        for i in range(32):
            tmp = (n >> i) & 1
            res += (tmp << (31-i))
        return res



        