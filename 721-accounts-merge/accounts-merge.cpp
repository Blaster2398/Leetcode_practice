class DSU
{
    public:
    vector<int> rank;
    vector<int> parent;
    
    DSU (int V){
        parent.resize(V);
        rank.resize(V, 0);  
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = find(parent[x]);
        }
    }
    
    void union_rank(int x, int y){
        int a = find(x);
        int b = find(y);
        
        if(a == b) return ;
        
        if(rank[a] < rank[b]) parent[a] = b;
        else if(rank[a] > rank[b]) parent[b] = a;
        else{
            parent[b] = a;
            rank[a++];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToAccount;
        DSU dsu(accounts.size());

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (emailToAccount.count(email)) {
                    dsu.union_rank(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> accountToEmails;
        for (const auto& [email, account] : emailToAccount) {
            int rootAccount = dsu.find(account);
            accountToEmails[rootAccount].push_back(email);
        }

        vector<vector<string>> mergedAccounts;
        for (auto& [account, emails] : accountToEmails) {
            sort(emails.begin(), emails.end());
            vector<string> accountList = {accounts[account][0]};
            accountList.insert(accountList.end(), emails.begin(), emails.end());
            mergedAccounts.push_back(accountList);
        }

        return mergedAccounts;
    }
};