class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // for faster searching purposes
        set<string> st;
        int flag = 0;
        for(string i : wordList){
            if(i == endWord) flag = 1;
            st.insert(i);
        }
        if(flag == 0) return 0;

        // do a BFS
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> check;
        while(!q.empty()){
            string word = q.front().first;
            int lvl = q.front().second;
            q.pop();

            if(word == endWord) return lvl;

            for(int i = 0; i < word.length(); i++){
                string orgword = word;
                for(int j = 0; j < 26; j++){
                    word[i] = 'a' + j;
                    if(word == orgword) continue;
                    if(st.find(word) != st.end() && check.find(word) == check.end()){
                        cout << word << endl;
                        check.insert(word);
                        q.push({word, lvl+1});
                    }
                }
                word = orgword;
            }
        }
        return 0;
    }

};