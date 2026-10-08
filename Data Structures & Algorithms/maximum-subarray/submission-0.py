class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = [0] * len(nums) 
        res[0] = nums[0]

        for idx in range(1, len(nums)):
            res[idx] = max(res[idx - 1] + nums[idx], nums[idx])
            
        return max(res)

