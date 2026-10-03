class NumArray:
    def __init__(self, nums: list[int]):
        self.nums = nums
        self.size = len(nums)
        self.prefix = [0] * (self.size + 1)
        self.prefix[0] = 0
        for i in range(1, self.size + 1):
            self.prefix[i] = self.prefix[i - 1] + self.nums[i - 1]

    def sumRange(self, left: int, right: int) -> int:
        return self.prefix[right + 1] - self.prefix[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
