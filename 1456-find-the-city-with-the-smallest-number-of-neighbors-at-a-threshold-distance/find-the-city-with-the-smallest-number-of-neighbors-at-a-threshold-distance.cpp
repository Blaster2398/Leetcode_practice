class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize adjacency matrix with "infinity"
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        
        // Set edge weights
        for (const auto& e : edges) {
            int i = e[0];
            int j = e[1];
            int wt = e[2];
            mat[i][j] = wt;
            mat[j][i] = wt;
        }

        // Set the diagonal to zero (distance from a node to itself)
        for (int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }

        // Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][via] < 1e9 && mat[via][j] < 1e9) { // Avoid overflow
                        mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                    }
                }
            }
        }

        // Count reachable cities within the distance threshold
        vector<int> reachableCities(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && mat[i][j] <= distanceThreshold) {
                    reachableCities[i]++;
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the threshold
        int minReachable = INT_MAX;
        int city = -1;
        for (int i = 0; i < n; i++) {
            if (reachableCities[i] <= minReachable) {
                minReachable = reachableCities[i];
                city = i;
            }
        }

        return city;
    }
};