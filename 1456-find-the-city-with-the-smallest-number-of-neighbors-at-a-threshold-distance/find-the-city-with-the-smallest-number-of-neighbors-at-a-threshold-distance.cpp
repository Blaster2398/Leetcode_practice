class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(auto e : edges){
            int i = e[0];
            int j = e[1];
            int wt = e[2];
            mat[i][j] = wt;
            mat[j][i] = wt;
        }
        for(int i = 0; i <n; i++){
            mat[i][i] = 0;
        }

        for(int i = 0; i <n; i++){
            for(int j =0;j <n; j++){
                cout << mat[i][j] << " " ;
            }

            cout << endl;
        }
        cout << endl;
        cout << endl;
        
        for(int via = 0; via <n; via++){
            for(int i = 0; i <n; i++){
                for(int j =0;j <n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }

        for(int i = 0; i <n; i++){
            for(int j =0;j <n; j++){
                cout << mat[i][j] << " " ;
            }

            cout << endl;
        }

        vector<int> res(n, 0);

        for(int i = 0; i <n; i++){
            for(int j =0;j <n; j++){
                if(mat[i][j] <= distanceThreshold && mat[i][j] != 0){
                    res[i]++;
                }
            }
        }

        int mini = 1e9;
        int ind = 0;
        for(int i = 0; i < n; i++){
            cout << "res[" << i << "] " << res[i] <<endl; 
            if(res[i] <= mini){
                mini = res[i];
                ind = i;
            }
        }
        return ind;

    }
};