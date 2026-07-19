class Solution {
public:
    string smallestSubsequence(string s) {
        int cnt[26] = {}, vis[26] = {};
        for (char c : s) cnt[c - 'a']++;
        string res = "";
        for (char c : s) {
            cnt[c - 'a']--;
            if (vis[c - 'a']) continue;
            while (!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0) {
                vis[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(c);
            vis[c - 'a'] = 1;
        }
        return res;
    }
};