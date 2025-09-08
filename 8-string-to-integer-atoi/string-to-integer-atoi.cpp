class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long num = 0;
        int sign = 1;
       
        while( i < s.size() && s[i] == ' ') i++;

        if(i < s.size() && s[i] == '-') {
            sign = -1;
            i++;
        }
        if(s[i] == '+' && sign != -1) i++;

        while(i < s.size() && isdigit(s[i])){
            num = 10*num + (s[i] - '0');
            if(sign == 1 && num > INT_MAX) return INT_MAX;
            if(sign == -1 && num > 1LL*INT_MAX + 1) return INT_MIN;
            i++;
        }

        return (int)(sign*num);
    }
};