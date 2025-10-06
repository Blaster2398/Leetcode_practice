class Solution {
public:
    int calculate(string str) {
        stack<int> st;
        st.push(1); // global environment
        int sign = 1;
        long long total = 0;

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];

            if (c == ' ') continue;

            // case 1: number
            if (isdigit(c)) {
                long long num = 0;
                while (i < str.size() && isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                i--;
                total += sign * num;
            }
            // case 2: plus or minus
            else if (c == '+') {
                sign = st.top();
            }
            else if (c == '-') {
                sign = -st.top();
            }
            // case 3: open bracket
            else if (c == '(') {
                st.push(sign);
            }
            // case 4: close bracket
            else if (c == ')') {
                st.pop();
            }
        }

        return (int)total;
    }
};
