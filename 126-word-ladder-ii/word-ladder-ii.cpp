class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string>& seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        int sz = word.size();
        for(int i = 0; i < sz; i++){
            int org = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(mp.find(word) != mp.end() && mp[word] == steps - 1){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }    

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b = beginWord;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;

        q.push(b);
        mp[b] = 1;
        int sz = b.size();
        st.erase(b);

        while(!q.empty()){
            auto word = q.front(); q.pop();
            int steps = mp[word];
            
            if(word == endWord) break;

            for(int i = 0; i < sz; i++){
                char org = word[i];
                for(char c  ='a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.count(word)){
                        mp[word] = steps + 1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = org;
            }
        }

        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;

    }
};