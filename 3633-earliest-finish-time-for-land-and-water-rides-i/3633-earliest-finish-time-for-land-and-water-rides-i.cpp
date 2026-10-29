class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int landFirstFinish = max(landStartTime[i], 0) + landDuration[i];
                int totalTimeLandFirst = max(waterStartTime[j], landFirstFinish) + waterDuration[j];
                
                int waterFirstFinish = max(waterStartTime[j], 0) + waterDuration[j];
                int totalTimeWaterFirst = max(landStartTime[i], waterFirstFinish) + landDuration[i];

                minFinishTime = min({minFinishTime, totalTimeLandFirst, totalTimeWaterFirst});
            }
        }

        return minFinishTime;
    }
};