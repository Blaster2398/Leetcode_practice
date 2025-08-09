class SegmentTree{
    int n;
    vector<vector<int>> tree;

    int getDepth(long long x){
        int d = 0;
        while(x > 1){
            x = __builtin_popcountll(x);
            d++;
        }
        return d;
    }

    void build(int l, int r, int node, vector<long long>& nums){
        if(l == r){
           int depth = getDepth(nums[l]);
           tree[node][depth] = 1;
           return;
        }
        int mid = (l + r) /2;
        build(l, mid, 2*node, nums);
        build(mid+1, r, 2*node+1, nums);
        
        // merge logic
        for(int i = 0; i < 6; i++) tree[node][i] = tree[2*node][i] + tree[2*node+1][i];

    }

    void update(int l , int r, int node, int idx, long long val){
        if(l == r){
            tree[node] = vector<int>(6, 0);
            int depth = getDepth(val);
            tree[node][depth] = 1;
            return;
        }
        int mid = (l + r) /2;
        if(idx <= mid) update(l , mid, 2*node, idx, val);
        else update(mid+1, r, 2*node+1, idx, val);

        // merge logic 
        for(int i = 0; i < 6; i++) tree[node][i] = tree[2*node][i] + tree[2*node+1][i];

    }

    int query( int l, int r, int node, int ql, int qr, int k){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node][k];
        int mid = (l + r)/ 2;
        return (query(l, mid, 2*node, ql, qr, k) + 
                query(mid+1, r, 2*node+1, ql, qr, k));
    }


public:
    SegmentTree(vector<long long>& nums){
        this->n = nums.size();
        tree.resize(4*n, vector<int>(6, 0));
        build(0, n-1, 1, nums);
    }

    void update(int idx, long long val){
        update(0, n-1, 1, idx, val);
    }

    int getCount(int l, int r, int k){
        return query(0, n-1, 1, l, r, k);
    }

    int size() const{
        return n;
    }

};
class Solution {
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        SegmentTree tree(nums);
        vector<int> res;
        for(auto & q: queries){
            if(q[0] == 1){
                int l = q[1], r = q[2], k = q[3];
                res.push_back(tree.getCount(l, r, k));
            }
            else{
                int idx = q[1];
                long long val = q[2];
                tree.update(idx ,val);
            }
        }
        return res;
    }
};