class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, l = 0, r = 0, fartest = 0;
        while(r < nums.size() - 1)
        {
            fartest = 0;
            for(int i = l; i <= r; i++)
            {
                fartest = max(fartest, i + nums[i]);
            }
            l = r + 1;
            r = fartest;
            res++;
        }
        return res;
    }
};
