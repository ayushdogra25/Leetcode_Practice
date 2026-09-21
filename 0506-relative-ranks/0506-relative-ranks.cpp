class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<int> sorted = score;      
        sort(sorted.begin(), sorted.end(), greater<int>());

        unordered_map<int, string> rank;

        for (int i = 0; i < n; i++) {
            if (i == 0) rank[sorted[i]] = "Gold Medal";
            else if (i == 1) rank[sorted[i]] = "Silver Medal";
            else if (i == 2) rank[sorted[i]] = "Bronze Medal";
            else rank[sorted[i]] = to_string(i + 1);
        }

        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = rank[score[i]];
        }

        return ans;
    }
};