class Solution {
private:
    vector<int> tree, lazy;

    // Đẩy giá trị chờ gán từ node id xuống hai node con.
    void push(int id) {
        if (lazy[id] == -1) return;

        tree[2 * id] = lazy[id];
        tree[2 * id + 1] = lazy[id];
        lazy[2 * id] = lazy[id];
        lazy[2 * id + 1] = lazy[id];
        lazy[id] = -1;
    }

    // Tìm chiều cao lớn nhất trên đoạn [L, R].
    // Node id quản lý đoạn [l, r].
    int query(int id, int l, int r, int L, int R) {
        if (r < L || l > R) {
            return INT_MIN;
        }

        if (l >= L && r <= R) {
            return tree[id];
        }

        push(id);
        int m = (l + r) / 2;
        int left = query(2 * id, l, m, L, R);
        int right = query(2 * id + 1, m + 1, r, L, R);
        return max(left, right);
    }

    void update(int id, int l, int r,
                int L, int R, int height) {
        if (r < L || l > R) {
            return;
        }

        if (l >= L && r <= R) { // CAN XEM KY
            lazy[id] = height;
            tree[id] = lazy[id];
            return; // K đc quên return ở đây
        }

        int m = (l + r) / 2;
        push(id);
        update(2 * id, l, m, L, R, height);
        update(2 * id + 1, m + 1, r, L, R, height);

        tree[id] = max(tree[2 * id], tree[2 * id + 1]);
    }

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        if (positions.empty()) return {};

        // 1. Thu thập tọa độ hai đầu của mỗi hình vuông.
        vector<int> coords;

        for (const auto& p : positions) {
            int left = p[0];
            int right = left + p[1] - 1;

            coords.push_back(left);
            coords.push_back(right);
        }

        // 2. Nén tọa độ.
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()),
                     coords.end());

        // n là số tọa độ khác nhau sau khi nén.
        int n = coords.size();

        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -1); // -1: không có phép gán đang chờ.

        vector<int> ans;
        int highest = 0;

        // 3. Xử lý lần lượt từng hình vuông.
        for (const auto& p : positions) {
            int left = p[0];
            int side = p[1];
            int right = left + side - 1;

            int L = lower_bound(coords.begin(), coords.end(), left)
                    - coords.begin();

            int R = lower_bound(coords.begin(), coords.end(), right)
                    - coords.begin();

            // TODO: Dùng query để lấy chiều cao nền trên [L, R].
            int curHeight = query(1, 0, n - 1, L, R);

            // TODO: Tính chiều cao đỉnh mới = chiều cao nền + side.
            int newHeight = curHeight + side;

            // TODO: Dùng update để gán chiều cao mới cho [L, R].
            update(1, 0, n - 1, L, R, newHeight);

            // TODO: Cập nhật highest.
            highest = max(highest, newHeight);

            // TODO: Thêm highest vào ans.
            ans.push_back(highest);
        }

        return ans;
    }
};