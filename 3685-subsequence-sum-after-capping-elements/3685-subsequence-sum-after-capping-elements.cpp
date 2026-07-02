class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end(), greater<int>());
        
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        dp[n][0] = true;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= k; ++j) {
                if (dp[i + 1][j]) {
                    dp[i][j] = true;
                    if (j + sorted_nums[i] <= k) {
                        dp[i][j + sorted_nums[i]] = true;
                    }
                }
            }
        }        
        vector<bool> answer(n, false);
        for (int x = 1; x <= n; ++x) {
            int t = 0;
            while (t < n && sorted_nums[t] > x) {
                t++;
            }           
            for (int s = 0; s <= k; ++s) {
                if (dp[t][s]) {
                    int rem = k - s;
                    if (rem >= 0 && rem % x == 0 && rem / x <= t) {
                        answer[x - 1] = true;
                        break;
                    }
                }
            }
        }
        
        return answer;
    }
};