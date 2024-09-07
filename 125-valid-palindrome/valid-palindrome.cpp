class Solution {
public:
    bool pall(string &s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start ++;
            end --;
        }
        return true;
    }
    bool isPalindrome(string s) {
        
        string str;
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] <= 57 && s[i] >=48)){
                str+= s[i];
            }
        }
        for (char &c : str) {
            c =tolower(c);
        }
        cout << str <<endl;
        int start = 0;
        int end = str.size()-1;
        return pall(str, start, end);
    }
};