class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt; //<值,次數>
        for(auto num : nums) 
        {
            cnt[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1); //freq[次數, 值set] , nums:[2,2,2] , index記0 , 1 , 2 , 3，大小要開nums.size() + 1
        for(auto pair : cnt) 
        {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for(int i = freq.size() - 1; i >= 0 ; i--) 
        {
            for(auto tmp : freq[i])
            {
                res.push_back(tmp);
                if(res.size() == k)
                    return res;
            }
        }




        
    }
};
