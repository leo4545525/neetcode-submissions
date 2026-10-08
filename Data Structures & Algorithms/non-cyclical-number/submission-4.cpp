class Solution {
public:
    int calEveryDigitSquare(int n)
    {
        int res = 0;
        int digit;
        while(n)
        {
            digit = n % 10;
            res += digit * digit;
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = calEveryDigitSquare(slow);
            fast = calEveryDigitSquare(calEveryDigitSquare(fast));
            if (slow == 1 || fast == 1) return true; // 走到 1
            if (slow == fast) return false;          // 落入循環
        }

        
    }
};
