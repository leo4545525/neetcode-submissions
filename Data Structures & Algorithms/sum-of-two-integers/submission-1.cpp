class Solution {
public:
    int getSum(int a, int b) {
        while(a)
        {
            int tmp = (a & b) << 1;
            b ^= a;
            a = tmp;
        }
        return b;
    }
};
