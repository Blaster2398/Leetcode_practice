class Solution {
public:
    bool findPartition(int start, int sum, int target, string str, vector<vector<int>>& dp){
        if(start == str.size()){
            return sum == target;
        }

        if(sum > target){
            return false;
        }

        if(dp[start][sum] != -1){
            return dp[start][sum];
        }

        bool partitionFound = false;

        for(int i = start; i < str.size(); i++){
            // create partition
            string partition = str.substr(start, i - start + 1);
            int addend = stoi(partition);

            partitionFound = (partitionFound || findPartition(i+1, sum + addend, target,  str, dp));

            if(partitionFound == true) return true;
        }
        return dp[start][sum] = partitionFound;
    }



    int punishmentNumber(int n) {
        int res = 0;
        
        for(int i = 1; i <= n; i++){
            int sq = i*i;
            string str = to_string(sq);
            vector<vector<int>> dp(str.size(), vector<int>(i+1, -1));
            if(findPartition(0, 0, i, str, dp)){
                res+= sq;
            }
        }
        return res;
    }
};