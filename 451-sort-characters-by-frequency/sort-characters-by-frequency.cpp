class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> c;
        for(char i : s){
            c[i]++;
        }
        vector<pair<char, int>> vec(c.begin(), c.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;   // ascending order
        });

        string res = "";
        for(auto [ch, n] : vec){
            cout << ch << " is " << n << " times" << endl;
            while(n--) res+= ch;
        }
        return res;
    }
};