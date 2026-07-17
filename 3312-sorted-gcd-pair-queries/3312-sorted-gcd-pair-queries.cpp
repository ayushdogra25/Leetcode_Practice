class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mv = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(mv + 1, 0), pairs(mv + 1, 0), pref(mv + 1, 0);
        for (int x : nums) cnt[x]++;
        
        for (int i = mv; i >= 1; i--) {
            long long m = 0;
            for (int j = i; j <= mv; j += i) m += cnt[j];
            pairs[i] = m * (m - 1) / 2;
            for (int j = 2 * i; j <= mv; j += i) pairs[i] -= pairs[j];
        }
        for (int i = 1; i <= mv; i++) pref[i] = pref[i - 1] + pairs[i];
        
        vector<int> ans;
        for (long long q : queries) {
            ans.push_back(upper_bound(pref.begin(), pref.end(), q) - pref.begin());
        }
        return ans;
    }
};