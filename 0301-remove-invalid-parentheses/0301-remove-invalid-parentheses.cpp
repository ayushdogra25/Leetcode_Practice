class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) {
                    left_rem--;
                } else {
                    right_rem++;
                }
            }
        }   
        vector<string> res;
        dfs(s, 0, left_rem, right_rem, res);
        return res;
    }
private:
    void dfs(string s, int start, int l, int r, vector<string>& res) {
        if (l == 0 && r == 0) {
            if (isValid(s)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            if (i != start && s[i] == s[i - 1]) continue;      
            if (s[i] == '(' || s[i] == ')') {
                string next_str = s.substr(0, i) + s.substr(i + 1);
                
                if (r > 0 && s[i] == ')') {
                    dfs(next_str, i, l, r - 1, res);
                } else if (l > 0 && s[i] == '(') {
                    dfs(next_str, i, l - 1, r, res);
                }
            }
        }
    }
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            
            if (count < 0) return false;
        }
        return count == 0;
    }
};