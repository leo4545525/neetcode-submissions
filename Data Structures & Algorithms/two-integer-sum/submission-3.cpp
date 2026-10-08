class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; //val to idx
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(seen.count(complement))
                return {seen[complement], i};
            else
                seen[nums[i]] = i;
        }
        return {};
    }
};
