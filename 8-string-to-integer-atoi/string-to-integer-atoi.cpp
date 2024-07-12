#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long ans = 0;  // Use long to handle overflow during calculation
        int i = 0;
        
        // Skip leading spaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        
        // Handle sign
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Convert digits
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow before updating ans
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            ans = ans * 10 + digit;
            i++;
        }
        
        return sign * ans;
    }
};
