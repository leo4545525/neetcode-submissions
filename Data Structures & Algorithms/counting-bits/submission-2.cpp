class Solution {
public:
    vector<int> countBits(int n) {
        int cnt;
        vector<int> res;
        for(int i = 0 ; i <= n ; i++)
        {
            cnt = 0;
            int num = i;
            while(num)
            {
                num &= (num - 1);
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
        
    }
};
