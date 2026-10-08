class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow)
                break;
        }
        int finder = 0;
        while(1)
        {
            slow = nums[slow];
            finder = nums[finder];
            if(slow == finder)
                return finder;
        }
    }
};
