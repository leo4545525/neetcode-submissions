class Solution {
public:
    // 儲存所有 subset
    vector<vector<int>> res;

    // 目前這條 DFS 路徑選了哪些數字
    vector<int> subset;

    void dfs(vector<int>& nums, int idx)
    {
        // 所有數字都已經決定完「選 / 不選」
        // 把目前 subset 存進答案
        if (idx == nums.size())
        {   
            res.push_back(subset);
            return;
        }

        // 1. 選 nums[idx]
        subset.push_back(nums[idx]);

        // 繼續決定下一個數字
        dfs(nums, idx + 1);

        // 2. Backtracking：
        // 撤銷剛剛「選 nums[idx]」的決定，恢復原本狀態
        subset.pop_back();

        // 3. 不選 nums[idx]，直接決定下一個數字
        dfs(nums, idx + 1);        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int idx = 0;

        // 從第一個數字開始做「選 / 不選」
        dfs(nums, idx);

        return res;
    }
};