// class Solution {
// public:
//     bool findPartition(int start, int sum, int target, string str, vector<vector<int>>& dp){
//         if(start == str.size()){
//             return sum == target;
//         }

//         if(sum > target){
//             return false;
//         }

//         if(dp[start][sum] != -1){
//             return dp[start][sum];
//         }

//         bool partitionFound = false;

//         for(int i = start; i < str.size(); i++){
//             // create partition
//             string partition = str.substr(start, i - start + 1);
//             int addend = stoi(partition);

//             partitionFound = (partitionFound || findPartition(i+1, sum + addend, target,  str, dp));

//             if(partitionFound == true) return true;
//         }
//         return dp[start][sum] = partitionFound;
//     }



//     int punishmentNumber(int n) {
//         int res = 0;
        
//         for(int i = 1; i <= n; i++){
//             int sq = i*i;
//             string str = to_string(sq);
//             vector<vector<int>> dp(str.size(), vector<int>(i+1, -1));
//             if(findPartition(0, 0, i, str, dp)){
//                 res+= sq;
//             }
//         }
//         return res;
//     }
// };

// this is the 2nd solution with recursion on string 
class Solution {
public:
    bool canPartition(string stringNum, int target) {
        // Valid Partition Found
        if (stringNum == "" && target == 0) return true;

        // Invalid Partition Found
        if (target < 0) return false;

        // Recursively check all partitions for a valid partition
        for (int index = 0; index < stringNum.size(); index++) {
            string left = stringNum.substr(0, index + 1);
            string right = stringNum.substr(index + 1);
            int leftNum = stoi(left);

            if (canPartition(right, target - leftNum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            // Check if valid partition can be found and add squared number if
            // so
            if (canPartition(to_string(squareNum), currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};