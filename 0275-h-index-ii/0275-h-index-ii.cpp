class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int papersWithMoreCitations = n - mid;   
            if (citations[mid] == papersWithMoreCitations) {
                return papersWithMoreCitations;
            }
            else if (citations[mid] < papersWithMoreCitations) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return n - low;
    }
};