#include <iostream>
#include <vector>

using namespace std;

int n, q;

void updateRange(
    vector<long long>& nums,
    vector<long long>& tree,
    int id,
    int a,
    int b,
    long long u,
    int left,
    int right
) {
    if (left >= a && right <= b) {
        tree[id] += u;
        return;
    }

    if (right < a || left > b) {
        return;
    }

    int mid = (left + right) / 2;
    updateRange(nums, tree, 2 * id, a, b, u, left, mid);
    updateRange(nums, tree, 2 * id + 1, a, b, u, mid + 1, right);
}

long long getValue(
    vector<long long>& nums,
    vector<long long>& tree,
    int id,
    int pos,
    int left,
    int right
) {
    if (left == right) {
        return nums[pos] + tree[id];
    }

    int mid = (left + right) / 2;
    if (pos <= mid) {
        return tree[id] + getValue(nums, tree, 2 * id, pos, left, mid);
    }
    else if (pos > mid) {
        return tree[id] + getValue(nums, tree, 2 * id + 1, pos, mid + 1, right);
    }
}

int main() {
    cin >> n >> q;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<long long> tree(4 * n);
    int buffer;
    for (int i = 0; i < q; i++) {
        cin >> buffer;
        if (buffer == 1) {
            int a, b;
            long long u;
            cin >> a >> b >> u;
            updateRange(nums, tree, 1, a - 1, b - 1, u, 0, n - 1);
        }
        else if (buffer == 2) {
            int k;
            cin >> k;
            cout << getValue(nums, tree, 1, k - 1, 0, n - 1) << endl;
        }
    }
    return 0;
}
