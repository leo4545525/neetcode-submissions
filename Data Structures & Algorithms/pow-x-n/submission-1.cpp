class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        
        double res = 1;
        long pow = abs((long)n);

        while(pow)
        {
            if(pow & 1)
            {
                res *= x;
            }
            x *= x;
            pow /= 2;
        }

        return n >= 0 ? res : 1 / res;
    }
};
