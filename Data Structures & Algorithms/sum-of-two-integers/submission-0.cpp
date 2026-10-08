class Solution {
public:
    int getSum(int xorr, int carry) {
        while(carry != 0)
        {
            int tmp = (xorr & carry) << 1;
            xorr = xorr ^ carry;
            carry = tmp;
        }
        return xorr;
    }
};
