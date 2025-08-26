class Solution {
public:
    string countAndSay(int n) {
        int count = 1;
        string s = "1";
        while(count < n){
            string nw = "";
            int j = 0;
            while(j < s.size()){
                int i = j;
                char num = s[j];
                while(j < s.size() && s[j+1]== num) j++;
                int dis = j - i + 1;
                nw += to_string(dis) + num;
                j++;
            }
            cout << nw << " string " << count << endl; 
            s = nw;
            count++;
        }
        return s;
    }
};