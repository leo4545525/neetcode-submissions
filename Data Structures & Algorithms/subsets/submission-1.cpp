class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res {{}};
        for(auto num : nums)
        {
            int res_size = res.size();
            for(int i = 0; i < res_size; i++)
            {
                vector<int> subset;
                subset = res[i];
                subset.push_back(num);
                res.push_back(subset);
            }
        }
        return res;
    }
};
