class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < nums1.size(); i++){
            sum1+= nums1[i];
            count1+= (nums1[i] == 0 ? 1 : 0);
        }
        for(int i = 0; i < nums2.size(); i++){
            sum2+= nums2[i];
            count2+= (nums2[i] == 0 ? 1 : 0);
        }
        if(count1 == 0 && sum1 < sum2 + count2){
            return -1;
        }
        if(count2 == 0 && sum2 < sum1 + count1){
            return -1;
        }
        
        return max(sum1 + count1, sum2 + count2);

    }
};