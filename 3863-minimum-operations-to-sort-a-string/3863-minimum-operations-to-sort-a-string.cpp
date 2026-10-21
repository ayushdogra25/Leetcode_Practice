class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;
        
        char min_mid = s[1], max_mid = s[1];
        for (int i = 1; i < n - 1; ++i) {
            min_mid = min(min_mid, s[i]);
            max_mid = max(max_mid, s[i]);
        }
        
        if (s[0] <= min(min_mid, s[n - 1]) || s[n - 1] >= max(s[0], max_mid)) {
            return 1;
        }
        
        if (s[n - 1] < min_mid && max_mid < s[0]) {
            return 3;
        }
        
        return 2;
    }
};