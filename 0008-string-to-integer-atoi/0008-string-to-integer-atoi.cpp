class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++; 
        bool isneg = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') isneg = true;
            i++;
        }

        long long result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (result > (INT_MAX - digit) / 10) {
                return isneg ? INT_MIN : INT_MAX;
            }

            result = result * 10 + digit;
            i++;
        }

        return isneg ? -result : result;
    }
};
