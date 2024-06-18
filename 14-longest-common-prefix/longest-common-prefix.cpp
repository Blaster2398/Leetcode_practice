class Solution {
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     if (strs.empty()) return "";
        
    //     string prefix = strs[0];
    //     for (int i = 1; i < strs.size(); i++) {
    //         int j = 0;
    //         // Find the common prefix between prefix and strs[i]
    //         while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
    //             j++;
    //         }
    //         // Update the prefix
    //         prefix = prefix.substr(0, j);
    //         // If there is no common prefix
    //         if (prefix.empty()) {
    //             return "";
    //         }
    //     }
    //     return prefix;
    // }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = "";

        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    return res;
                }
            }
            res+=strs[0][i];
        }
        return res;
    }
};
