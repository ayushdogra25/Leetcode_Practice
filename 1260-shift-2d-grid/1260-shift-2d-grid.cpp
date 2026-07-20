class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), total = m * n;
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < total; ++i)
            res[(i + k) % total / n][(i + k) % total % n] = grid[i / n][i % n];
        return res;
    }
};