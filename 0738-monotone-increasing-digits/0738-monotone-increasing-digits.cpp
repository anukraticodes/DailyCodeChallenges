class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int marker = num.size();
        
        
        for (int i = num.size() - 1; i > 0; --i) {
            if (num[i] < num[i - 1]) {
                marker = i;
                num[i - 1]--;  
            }
        }
        
        
        for (int i = marker; i < num.size(); ++i) {
            num[i] = '9';
        }
        
        return stoi(num);
    }
};