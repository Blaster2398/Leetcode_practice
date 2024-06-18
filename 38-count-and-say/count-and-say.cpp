class Solution {
public:
    string f(int n){
        string res = "";
        // base case 
        if(n == 1){
            return "1";
        }
        res =res + f(n-1);
        // now do the RLE
        int count = 1;
        string newres = "";
        for(int i = 0; i < res.length()-1; i++){
            if(res[i] == res[i+1]){
                count++;
            }
            else{
                newres += to_string(count) + res[i];
                count = 1;
            }
        }
        newres += to_string(count) + res.back();
        
        return newres;
    }
    string countAndSay(int n) {
        return f(n);
    }
};