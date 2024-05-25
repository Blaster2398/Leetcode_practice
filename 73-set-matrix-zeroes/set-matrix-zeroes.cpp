class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        unordered_set<int> r;
        unordered_set<int> c; 
        for(int i =0; i<row; i++){
            for(int j =0; j < col; j++){
                if(matrix[i][j] == 0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for(auto &u : r){
            for(int i = 0; i < col; i++){
                matrix[u][i] =0;
            }
        }
        for(auto &u : c){
            for(int i = 0; i < row; i++){
                matrix[i][u] =0;
            }
        }
    }
};