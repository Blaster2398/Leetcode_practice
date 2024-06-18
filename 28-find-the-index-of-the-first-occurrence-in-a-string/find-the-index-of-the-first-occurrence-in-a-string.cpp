class Solution {
public:
    // int strStr(string haystack, string needle) {
    //     int h = haystack.size();
    //     int n = needle.size();
    //     for(int i = 0; i <= h - n +1; i++){
    //         if(haystack.substr(i,n) == needle){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    // very harsh 
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();

        if(needle == "") return 0;
        
        vector<int> lps(n, 0);
        int prev = 0;
        int curr = 1;

        // to fill the lps array 
        while(curr < n){
            if(needle[curr] == needle[prev]){
                lps[curr] = prev+1;
                prev++;
                curr++;
            }
            else if(prev == 0){
                lps[curr] = 0;
                curr++;
            }
            else{
                prev = lps[prev - 1];
            }
        }

        // now pattern matching 
        int i = 0; // pointer for haystack
        int j = 0; // pointer for needle
        while(i < h){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }
            if(j == n){
                return i - n;
            }
        }
        return -1;
    }
};