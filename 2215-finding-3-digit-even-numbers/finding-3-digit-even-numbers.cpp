class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        int n = digits.size();

        // Try all 3-digit permutations
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && j != k && i != k) {
                        int a = digits[i], b = digits[j], c = digits[k];

                        // First digit can't be zero, last digit must be even
                        if (a != 0 && c % 2 == 0) {
                            int num = a * 100 + b * 10 + c;
                            st.insert(num);
                        }
                    }
                }
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};
