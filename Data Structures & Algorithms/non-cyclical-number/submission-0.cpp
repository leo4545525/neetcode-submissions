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
        unordered_set<int> set;
        while(n)
        {
            n = calEveryDigitSquare(n);
            if(n == 1) 
                return true;
            if(set.count(n))
                return false;
            set.insert(n);
        }
    }
};
