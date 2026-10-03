class NumArray {
    int []sum;
    public NumArray(int[] nums) {
        int n = nums.length;
        sum = new int[n];
        sum[0] = nums[0];
        int tmp = sum[0];
        for(int i = 1; i<nums.length; i++){
            sum[i] = tmp + nums[i];
            tmp = sum[i];
        }
    }
    
    public int sumRange(int left, int right) {
        if(left == 0) return sum[right];
        else{
            return sum[right] - sum[left - 1];
        }
    }
}
