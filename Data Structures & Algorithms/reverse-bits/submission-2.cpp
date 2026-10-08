class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t getRightmostOne, res = 0;
        for(int i = 0; i < 32; i++)
        {
            getRightmostOne = (n >> i) & 1;
            res += (getRightmostOne << (31 - i));
        }
        return res;
    }
};
