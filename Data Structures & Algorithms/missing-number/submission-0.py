class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        tmp = 0
        for val in nums:
            tmp ^= val
        for i in range(len(nums)+1):
            tmp ^= i
        return tmp