class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        unsigned long long x = 0;
        for(auto digit : digits)
        {
            x = 10 * x + digit;
        }
        //cout << x;
        x++;

        vector<int> res;
        for(auto c : to_string(x))
            res.push_back(c - '0');
        
        return res;
    }
};
