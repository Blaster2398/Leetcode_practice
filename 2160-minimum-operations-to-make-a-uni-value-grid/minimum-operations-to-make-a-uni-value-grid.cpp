class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int result = 0;

        // flatten the matrix
        for(int i = 0;i < grid.size(); i++){
            for(int j = 0;j < grid[0].size(); j++){
                arr.push_back(grid[i][j]);
            }
        }
        int length = arr.size();

        //find the median
        nth_element(arr.begin(), arr.begin() + length/2 , arr.end());

        int fin_num = arr[length/2];

        // check if it is possible 
        for(int i : arr){
            if(i % x != fin_num % x) return -1;
            result += abs(fin_num - i) / x;
        }

        return result;

    }
};