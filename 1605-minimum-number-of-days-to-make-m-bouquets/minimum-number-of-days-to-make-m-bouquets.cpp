class Solution {
public:
    bool geek(vector<int>& nums, int m, int k, int mid){
        int i = 0;
        int ans = 0;
        int seq = k;
        while(i < nums.size()){
            if(ans >= m) return true;

            if(nums[i] > mid) seq = k;
            else seq--;

            if(seq == 0){
                
                ans++;
                seq = k;
            }
            i++;
        }
        
        return (ans >= m);
    }
    int minDays(vector<int>& nums, int m, int k) {
        if(m > nums.size()) return -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans  = -1;
        while(low <= high){
            int mid = (low + high)/2; 
            bool check= geek(nums, m, k, mid);
            if(check){
                high = mid -1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans ;
    }
};