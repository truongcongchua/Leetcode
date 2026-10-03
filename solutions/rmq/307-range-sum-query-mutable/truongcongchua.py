class NumArray:
    def __init__(self, nums: list[int]):
        self.nums = nums
        self.size = len(nums)
        self.tree = [0] * (4 * self.size)
        self.build(1, 0, self.size - 1)

    def build(self, id, left, right):
        if left == right:
            self.tree[id] = self.nums[left]
            return

        mid = (left + right) // 2
        self.build(2 * id, left, mid)
        self.build(2 * id + 1, mid + 1, right)
        self.tree[id] = self.tree[2 * id] + self.tree[2 * id + 1]

    def update(self, index: int, val: int) -> None:
        def update_helper(id, index, val, left, right):
            if left == right:
                self.nums[index] = val
                self.tree[id] = val
                return

            mid = (left + right) // 2
            if index <= mid:
                update_helper(2 * id, index, val, left, mid)
            else:
                update_helper(2 * id + 1, index, val, mid + 1, right)

            self.tree[id] = self.tree[2 * id] + self.tree[2 * id + 1]

        update_helper(1, index, val, 0, self.size - 1)

    def sumRange(self, left: int, right: int) -> int:
        def query_helper(id, left, right, u, v):
            if right < u or left > v:
                return 0

            if left <= u and v <= right:
                return self.tree[id]

            mid = (u + v) // 2
            leftSum = query_helper(2 * id, left, right, u, mid)
            rightSum = query_helper(2 * id + 1, left, right, mid + 1, v)
            return leftSum + rightSum

        return query_helper(1, left, right, 0, self.size - 1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
