class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> pairs;
        // 1. 統計每個數字出現次數
        for(auto num:nums)
        {
            pairs[num]++;
        }
        // 2. 根據出現次數分組
        int buc_size = nums.size() + 1;
        
        vector<vector<int>> bucket(buc_size);
        for(auto p:pairs)
        {
            bucket[p.second].push_back(p.first);
        }
        // 3. 從最高頻率往下找
        vector<int> res;
        for(int i = nums.size(); i >= 0; i--)
        {
            for(int num:bucket[i])
            {
                res.push_back(num);
                if(res.size() == k)
                    return res;
            }
        }
        
    }
};
