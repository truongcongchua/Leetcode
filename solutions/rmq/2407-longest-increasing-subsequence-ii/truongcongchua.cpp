class Solution {
public:
    void build(vector<int>& dp, vector<int>& tree, int id, int left, int right) {
        if (left == right) {
            tree[id] = dp[left];
            return;
        }

        int mid = (left + right) / 2;
        build(dp, tree, 2 * id, left, mid);
        build(dp, tree, 2 * id + 1, mid + 1, right);
        tree[id] = max(tree[2 * id], tree[2 * id + 1]);
    }

    void update(vector<int>& dp, vector<int>& tree, int id, int pos, int val, int left, int right) {
        if (left == right) {
            dp[pos] = val;
            tree[id] = val;
            return;
        }

        int mid = (left + right) / 2;
        if (pos <= mid) {
            update(dp, tree, 2 * id, pos, val, left, mid);
        }
        else {
            update(dp, tree, 2 * id + 1, pos, val, mid + 1, right);
        }
        tree[id] = max(tree[2 * id], tree[2 * id + 1]);
    }

    int getMax(vector<int>& tree, int id, int u, int v, int left, int right) {
        if (right < u || left > v) {
            return INT_MIN;
        }

        if (left >= u && right <= v) {
            return tree[id];
        }

        int mid = (left + right) / 2;
        return max(getMax(tree, 2 * id, u, v, left, mid), getMax(tree, 2 * id + 1, u, v, mid + 1, right));
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAX_POS = *max_element(nums.begin(), nums.end());
        vector<int> dp(MAX_POS + 1, 1);
        vector<int> tree(4 * (MAX_POS + 1)); // ko cần dùng hàm build
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[nums[i]] = max(dp[nums[i]], 1 + getMax(tree, 1, nums[i] - k, nums[i] - 1, 0, MAX_POS));
            update(dp, tree, 1, nums[i], dp[nums[i]], 0, MAX_POS);
            res = max(res, dp[nums[i]]);
        }
        return res;
    }
};