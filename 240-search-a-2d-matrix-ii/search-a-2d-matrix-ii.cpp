class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        sort(nums.begin(), nums.end());
        while (low <= high){
            int mid = (low + high) / 2;
            if(target == nums[mid]){
                return true;
            }
            else if(target < nums[mid]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(target >= matrix[i][0] && target <= matrix[i][m-1]){
                flag |= (search(matrix[i], target));
            }
        }

        return flag;
    }
};