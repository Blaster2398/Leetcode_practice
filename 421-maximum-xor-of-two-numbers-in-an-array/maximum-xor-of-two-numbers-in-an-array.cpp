class TrieNode{
public:
    TrieNode* child[2];
    TrieNode(){
        for (int i = 0; i < 2; i++) {
            child[i] = NULL;
        }
    }
};
class Solution {
    TrieNode* root;
public:
    Solution() {
        root = new TrieNode(); // Initialize root in the constructor
    }
    void insert(int num) { 
        TrieNode* curr = root;
        bitset<32> bs(num);

        for( int i = 31; i>=0; i--){
            if(curr->child[bs[i]] == NULL){
                curr->child[bs[i]] =new TrieNode();
            }
            curr = curr->child[bs[i]];
        }
    }

    int maxUtil(int num) {
    TrieNode* curr = root;
    bitset<32> bs(num);
    int result = 0;
    for(int i = 31; i >= 0; i--){
        if(curr->child[!bs[i]] != NULL){
            //set the ith bit in the result as it will be one 
            result += 1<<i;
            curr = curr->child[!bs[i]];
        }
        else{// just leave that zero which will be automatic in the ans
            curr = curr->child[bs[i]];
        }
    }
    
    return result;
}


    int findMaximumXOR(vector<int>& nums) {
        int mux = 0;
        for(auto &n : nums){
            insert(n);
        }
        for(auto &n: nums){
            mux = max(mux, maxUtil(n));
        }
        return mux;
    }
};