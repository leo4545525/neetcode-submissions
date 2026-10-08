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
        do
        {
            slow = calEveryDigitSquare(slow);
            fast = calEveryDigitSquare(calEveryDigitSquare(fast));   
            
        } while(slow != fast);

        return slow == 1;
    }
};
