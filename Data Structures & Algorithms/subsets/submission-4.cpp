class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    void dfs(vector<int>& nums, int idx)
    {
        if(idx == nums.size())
        {   
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        dfs(nums, idx + 1);


        subset.pop_back();
        dfs(nums, idx + 1);        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int idx = 0;
        dfs(nums, idx);
        return res;
    }
};
