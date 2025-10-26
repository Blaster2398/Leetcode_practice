class DSU{
    public:
    vector<int> p, r;
    DSU(int n){
        p.resize(n);
        r.assign(n,1);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int v){
        if(p[v] == v) return v;
        return p[v] = find(p[v]);
    }
    void unite(int u, int v){
        int a = find(u);
        int b = find(v);
        if(a == b) return;
        if(r[a] > r[b])p[b] = a;
        else if(r[b] > r[a]) p[a] = b;
        else{
            p[b] = a;
            r[a]++;
        }
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums){
        int n = nums.size();
        
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end());

        int mx = nums2[n-1];
        DSU d(mx+1);

        for(int i = 0; i < n; i++){
            for(int j = 2; j*j <= nums[i]; j++){
                if(nums[i] % j == 0){
                    d.unite(nums[i] , j);
                    d.unite(nums[i], nums[i]/j);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(d.find(nums[i]) != d.find(nums2[i])) return false;
        }

        return true;
    }
};