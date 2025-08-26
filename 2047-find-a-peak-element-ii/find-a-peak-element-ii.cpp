class Solution {
public:
    pair<int,int> geek(vector<vector<int>>&mat, int mid){
        int ind = -1;
        int maxi = 0;
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][mid] > maxi){
                ind = i;
                maxi = mat[i][mid];
            }
        }

        int left = (mid == 0) ? INT_MIN : mat[ind][mid-1];
        int right = (mid == mat[0].size()-1) ? INT_MIN : mat[ind][mid+1];
        if(maxi > left && maxi > right) return {0, ind};
        else if(maxi < left) return {1, 1};
        else return {-1,-1};
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;
        while(low <= high){
            int mid = (low + high) / 2;
            auto [check, ind] = geek(mat, mid);
            if(check == 0) return {ind, mid};
            else if(check == 1) high = mid - 1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};