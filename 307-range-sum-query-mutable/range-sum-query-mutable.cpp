class NumArray {
public:
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4LL * n, 0);  // Use 4LL to avoid overflow in resize
        build_tree(0, n - 1, 1LL, nums);
    }

    void update(int index, int val) {
        update_tree(0, n - 1, 1LL, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, n - 1, 1LL, left, right);
    }

    int merge(int l, int r) {
        return l + r;
    }

    void build_tree(long long start, long long end, long long node, const vector<int>& nums) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        long long mid = start + (end - start) / 2;
        build_tree(start, mid, 2 * node, nums);
        build_tree(mid + 1, end, 2 * node + 1, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update_tree(long long start, long long end, long long node, int index, int val) {
        if (start == index && end == index) {
            tree[node] = val;
            return;
        }
        long long mid = start + (end - start) / 2;
        if (index <= mid)
            update_tree(start, mid, 2 * node, index, val);
        else
            update_tree(mid + 1, end, 2 * node + 1, index, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    int query(long long start, long long end, long long node, long long left, long long right) {
        if (left > right) return 0;
        if (start == left && end == right) return tree[node];
        long long mid = (start + end) / 2;
        return merge(
            query(start, mid, 2 * node, left, min(right, mid)),
            query(mid + 1, end, 2 * node + 1, max(left, mid + 1), right)
        );
    }
};
