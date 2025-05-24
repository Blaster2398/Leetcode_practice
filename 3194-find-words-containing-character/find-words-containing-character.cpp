class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i = 0; i < words.size(); i++){
            int flag = false;
            for(int j = 0; j < words[i].size(); j++){
                if(x == words[i][j]){
                    flag = true;
                }
            }
            if(flag == true ) res.push_back(i);
        }
        return res;
    }
};