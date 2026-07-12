class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            string s = to_string(num);
            int sum = 0;

            for (int i = 0; i < s.length(); i++) {
                sum += s[i] - '0';
            }
            num = sum;
        }
        return num;
    }
};