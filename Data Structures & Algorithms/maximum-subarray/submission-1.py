class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = [0] * len(nums) 
        res[0] = nums[0]
    
        def dp(i):
            return max(res[i - 1] + nums[i], nums[i])

        for i in range(1, len(nums)):
            res[i] = dp(i)

        return max(res)

