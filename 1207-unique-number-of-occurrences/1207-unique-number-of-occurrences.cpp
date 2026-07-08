class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<int> freq;
        int count = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }

        freq.push_back(count);

        for (int i = 0; i < freq.size(); i++) {
            for (int j = i + 1; j < freq.size(); j++) {
                if (freq[i] == freq[j]) {
                    return false;
                }
            }
        }

        return true;
    }
};