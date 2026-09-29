class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        int max_len = m + n;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(max_len, false)));
        
        auto dfs = [&](auto& self, int r, int c, int bal) -> bool {
            if (grid[r][c] == '(') bal++;
            else bal--;
            
            if (bal < 0) return false;
            
            if (r == m - 1 && c == n - 1) return bal == 0;
            
            if (visited[r][c][bal]) return false;
            visited[r][c][bal] = true;
            
            if (r + 1 < m && self(self, r + 1, c, bal)) return true;
            if (c + 1 < n && self(self, r, c + 1, bal)) return true;
            
            return false;
        };
        
        return dfs(dfs, 0, 0, 0);
    }
};