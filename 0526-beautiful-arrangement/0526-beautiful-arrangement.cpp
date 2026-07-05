class Solution {
private:
    int count = 0;
    void backtrack(int n, int pos, vector<bool>& visited) {
        if (pos == 0) {
            count++;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                backtrack(n, pos - 1, visited);
                visited[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        backtrack(n, n, visited);
        return count;
    }
};