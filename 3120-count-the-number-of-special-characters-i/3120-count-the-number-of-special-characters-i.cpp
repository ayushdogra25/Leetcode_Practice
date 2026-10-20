class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower_mask = 0;
        int upper_mask = 0;
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                lower_mask |= (1 << (c - 'a'));
            } else if (c >= 'A' && c <= 'Z') {
                upper_mask |= (1 << (c - 'A'));
            }
        }
        return __builtin_popcount(lower_mask & upper_mask);
    }
};