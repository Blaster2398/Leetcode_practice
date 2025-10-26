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
int lcm(int a, int b){
    return a*b / gcd(a,b);
}
class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();

        DSU d(threshold+1);

        for(int i = 0; i < n; i++){
            if(nums[i] <= threshold){
                for(int j = nums[i]; j <= threshold; j+=nums[i]){
                    d.unite(nums[i], j);
                }
            }
        }

        unordered_set<int> st;
        for (int num : nums) {
            if (num <= threshold)
                st.insert(d.find(num));
            else
                st.insert(num); 
        }
        return st.size();
    }
};