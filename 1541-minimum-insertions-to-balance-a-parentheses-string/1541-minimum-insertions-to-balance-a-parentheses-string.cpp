class Solution {
public:
    int minInsertions(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int ans = 0, needed = 0;
        for (char c : s) {
            if (c == '(') {
                if (needed % 2 != 0) {
                    ans++;
                    needed--;
                }
                needed += 2;
            } else {
                needed--;
                if (needed < 0) {
                    ans++;
                    needed += 2;
                }
            }
        }
        return ans + needed;
    }
};