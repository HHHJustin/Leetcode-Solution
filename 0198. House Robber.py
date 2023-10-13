class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return max(nums)
        length = len(nums)
        dp = [0 for _ in range(length)]
        dp[0], dp[1] = nums[0], max(nums[0], nums[1])
        for i in range(2, length):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        return dp[-1]

# use dp to solve
# create a dp table with size L (len(nums))
# and dp[i] represent the maximum amount od money you and eob until the ith day.
# This goal of this problem is to calculate dp[-1] 
# -> The maximum amount of money you can rob until the last day

# formula
# condition 1 -> didn't rob yesterday (i - 1th day):
# rob today(ith day) to maximum the amount
# -> This can be written as dp[i - 2] + nums[i]
# because dp[i - 2] denotes the maximum amount of money you can rob until the day before yesterday.
# and nums[i] represent today rob

# condition 2 -> rob yesterday(i - 1th day)
# can't rob today -> This can written as dp[i - 1]
