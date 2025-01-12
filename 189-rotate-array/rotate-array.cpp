class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =  nums.size();

        vector<int> temp(n);
        k = n - k;
        while(k < 0) k = k + n;

        for(int i = 0; i< n; i++){
            temp[i] = nums[(i + k) % n];
        }

        for(int i = 0; i < n; i++){
            nums[i] = temp[i];
        }

    }
};