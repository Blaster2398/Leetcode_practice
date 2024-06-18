class Solution {
public:
    bool strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        for(int i = 0; i <= h - n +1; i++){
            if(haystack.substr(i,n) == needle){
                return true;
            }
        }
        return false;
    }
    // bool strStr(string haystack, string needle){
    //     int n = needle.size();
    //     int h = haystack.size();

    //     // if(n ==0) return true;
    //     vector<int> lps(n, 0);
    //     int prev = 0;
    //     int curr = 1;

    //     while(curr < n){
    //         if(needle[curr] == needle[prev]){
    //             lps[curr] = prev+1;
    //             prev++;
    //             curr++;
    //         }
    //         else if(prev == 0){
    //             lps[curr] = 0;
    //             curr++;
    //         }
    //         else{
    //             prev = lps[prev -1];
    //         }   
    //     }
    //     // pattern matching 
    //     int i = 0;
    //     int j = 0;
    //     while(i < h){
    //         if(haystack[i] == needle[j]){
    //             i++;
    //             j++;
    //         }
    //         else if(j == 0){
    //             i++;
    //         }
    //         else{
    //             j = lps[j-1];
    //         }
    //         if(j == n){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    int repeatedStringMatch(string a, string b) {
        if(b.length() == 0) return 0;

        if(a == b) return 1;

        string st = a; 
        int repeat = 1;
        while(st.length() < b.length()){
            st+= a;
            repeat++;
        }

        if(strStr(st, b)){
            return repeat;
        }

        if(strStr(st+a, b)){
            return repeat + 1;
        }

        return -1;


    }
};