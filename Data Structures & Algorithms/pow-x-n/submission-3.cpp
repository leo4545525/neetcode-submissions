class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        
        double res = 1;
        long pow = abs((long)n);

        while(pow)
        {
            if(pow & 1)  // 若此位為 1（奇數），把目前的 x 乘進結果
            {
                res *= x;
            }
            x *= x; // 基底平方（對應位左移）
            pow >>= 1;  // 指數右移一位（等於除以 2）
        }

        return n >= 0 ? res : 1 / res; // 負次方取倒數
    }
};
