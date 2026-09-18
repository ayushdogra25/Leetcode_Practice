class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX / 2);
        int left = 0, current_sum = 0;
        int min_length = INT_MAX / 2;
        int ans = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            if (current_sum == target) {
                int len = right - left + 1;
                if (left > 0 && min_len[left - 1] != INT_MAX / 2) {
                    ans = min(ans, len + min_len[left - 1]);
                }
                min_length = min(min_length, len);
            }
            min_len[right] = (right > 0) ? min(min_len[right - 1], min_length) : min_length;
        }
        
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};
