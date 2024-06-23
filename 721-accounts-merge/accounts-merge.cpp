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
        //step 1 make a map of email -> parent 
        map <string, int> help;
        DSU d(accounts.size());
        for(int i = 0; i < accounts.size(); i++){
            int desc = accounts[i].size();
            for(int j = 1; j < desc; j++){
                if(help.find(accounts[i][j]) != help.end()){
                    d.union_rank(help[accounts[i][j]], i);
                    continue;
                }
                help[accounts[i][j]] = i;
            }

        }
        for(auto i : help){
            cout << i.first << "->" << i.second<<endl;
        }
        vector<vector<string>> result(accounts.size());
        for(int i = 0; i < accounts.size(); i++){
            if(d.find(i) == i){
                result[i].push_back(accounts[i][0]);
            }
        }
        
        for(const auto& pair: help){
            string id = pair.first;
            int parent = d.find(pair.second);
            result[parent].push_back(id);
        }
        vector<vector<string>> ans;
        for(const auto & it : result){
            if(!it.empty()){
                ans.push_back(it);
            }
        }


        return ans;
    }
};