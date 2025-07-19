class Solution {
public:
// firstly i tried using dp using totalSum as the target (https://takeuforward.org/plus/dsa/problems/partition-a-set-into-two-subsets-with-minimum-absolute-sum-difference?tab=submissions)
// but it fails for -ve numbers ( we have to use meet at the middle approach)
    int solve(vector<int> sum1, vector<int> sum2,int total){
        int m = sum1.size(), n = sum2.size();
        int minDiff = INT_MAX;
        for(int i = 0; i < m; i++){
            int target = (total / 2)  -  sum1[i];
            int lb = lower_bound(sum2.begin(), sum2.end(), target) - sum2.begin();

            if(lb == sum2.size()){
                minDiff = min(minDiff,abs(total -  2*(sum1[i] + sum2[lb-1])));
            }   
            else if(lb == 0){
                minDiff = min(minDiff,abs(total - 2*(sum1[i] + sum2[lb])));
            }
            else{
                minDiff = min({minDiff,abs(total - 2*(sum1[i] + sum2[lb-1])),abs(total - 2*(sum1[i] + sum2[lb]))});
            }
        }
        return minDiff;
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int total = 0;
        vector<int> nums1, nums2;
        for(int i = 0; i < n; i++){
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i + n]);
            total+= (nums[i]+ nums[i+n]);
        }
        // now find all subset sum for both the arrays
        vector<int> sum1[n+1], sum2[n+1];
        for(int i = 0; i < (1 << n); i++){
            int tot1 = 0, tot2 = 0, count = 0;
            for(int j = 0; j < n; j++){
                if(i & ( 1 << j )){
                    tot1 += nums1[j];
                    tot2 += nums2[j];
                    count++;
                }
            }
            sum1[count].push_back(tot1);
            sum2[count].push_back(tot2);
        }

        // sort the 2nd arrays 
        for(int i = 0; i <= n; i++){
            sort(sum2[i].begin(), sum2[i].end());
        }
        
        int minDiff = INT_MAX;
        for(int i = 0; i <= n; i++){
            minDiff = min(minDiff, solve(sum1[i], sum2[n-i], total));
        }
        return minDiff;
    }
};