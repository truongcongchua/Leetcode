class Solution:
    def lengthOfLIS(self, nums: list[int], k: int) -> int:
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i] and nums[i] - nums[j] <= k:
                    dp[i] = max(dp[i], 1 + dp[j])
        return max(dp)