class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto dateToDay = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };
        
        int arriveA = dateToDay(arriveAlice);
        int leaveA = dateToDay(leaveAlice);
        int arriveB = dateToDay(arriveBob);
        int leaveB = dateToDay(leaveBob);
        
        int start = max(arriveA, arriveB);
        int end = min(leaveA, leaveB);
        
        return max(0, end - start + 1);
    }
};