class NumArray {
    int[]sum;
    int[]nums;
    public void buildTree(int[]nums, int v, int l, int r){
        if(l == r) sum[v] = nums[l];
        else{
            int m = (l+r)/2;
            buildTree(nums, 2*v, l, m);
            buildTree(nums, 2*v + 1, m+1, r);
            sum[v] = sum[2*v] + sum[2*v + 1]; 
        }
    }

    public void updateTree(int v, int l, int r, int index, int val){
        if(l == r) sum[v] = val;
        else{
            int m = (l+r)/2;
            if(index <= m){
                updateTree(2*v, l, m, index, val);
            }else{
                updateTree(2*v+1, m+1, r, index, val); 
            }
            sum[v] = sum[2*v] + sum[2*v + 1]; 
        }
    }

    public int query(int v, int tl, int tr, int l, int r){
        if(l > r) return 0;
        if(tl == l && tr == r) return sum[v];
        else{
            int tm = (tl + tr)/2;
            int s1 = query(2*v, tl, tm, l, Math.min(r, tm));
            int s2 = query(2*v + 1, tm + 1, tr, Math.max(l, tm + 1), r);
            return s1 + s2;
        }
    }

    public NumArray(int[] nums) {
        this.nums = nums;
        sum = new int[4 * nums.length];
        buildTree(nums, 1, 0, nums.length - 1);
    }
    
    public void update(int index, int val) {
        updateTree(1, 0, nums.length - 1, index, val);
    }
    
    public int sumRange(int left, int right) {
        return query(1, 0, nums.length - 1, left, right);
    }
}
