class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) { 
        TrieNode* curr = root; 
        for(auto c : word){
            if(curr->child[c-'a'] == NULL){
                TrieNode* newNode = new TrieNode();
                curr->child[c-'a'] = newNode;
            }
            curr = curr->child[c- 'a'];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for(auto c : word){
            if(curr->child[c-'a'] == NULL){
                return false;
            }
            curr = curr->child[c- 'a'];
        }
        return (curr->isEnd == true);
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c : prefix){
            if(curr->child[c-'a'] == NULL){
                return false;
            }
            curr = curr->child[c- 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */