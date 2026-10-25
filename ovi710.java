import java.util.Arrays;

class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if (sum % k != 0) {
            return false;
        }

        int target = sum / k;
        Arrays.sort(nums);

        if (nums[nums.length - 1] > target) {
            return false;
        }

        int[] buckets = new int[k];

        return backtrack(nums, nums.length - 1, buckets, target);
    }

    private boolean backtrack(int[] nums, int index, int[] buckets, int target) {
        if (index < 0) {
            return true;
        }
        int num = nums[index];
        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i] + num > target) {
                continue;
            }
            buckets[i] += num;
            if (backtrack(nums, index - 1, buckets, target)) {
                return true;
            }

            buckets[i] -= num;
            if (buckets[i] == 0) {
                break;
            }
        }

        return false;
    }
}
