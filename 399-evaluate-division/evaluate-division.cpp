class Solution {
public:
    void dfs(string node, string& dest, 
    unordered_map<string, unordered_map<string, double>>& gr, 
    unordered_set<string>& vis, double& res, double temp){
        if(vis.find(node) != vis.end()) return;

        vis.insert(node);
        if(node == dest){
            res = temp;
            return;
        }

        for(auto [it, val] : gr[node]){
            
            if(vis.count(it) == 0){
                dfs(it, dest, gr, vis, res, temp*val);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
    vector<double>& values, vector<vector<string>>& queries) {

        // build the graph   (a/b -> up / down)
        // string -> { string -> val , string - > val ....}
        unordered_map<string, unordered_map<string, double>> gr;

        for(int i = 0; i < equations.size(); i++){
            string up = equations[i][0];
            string down = equations[i][1];
            double val = values[i];
            gr[up][down] = val;
            gr[down][up] = 1.0 / val;

        }

        // we will store the ans in a vector<double
        vector<double> ans;

        for(auto q : queries){
            string up = q[0];
            string down = q[1];
            
            if(gr.find(up) == gr.end() || gr.find(down) == gr.end()){
                ans.push_back(-1.0);
            }
            else{
                unordered_set<string> vis;
                double res = -1.0 , temp = 1.0;
                dfs(up, down, gr, vis, res, temp);
                ans.push_back(res);
            }

        }
        return ans;
    }
};