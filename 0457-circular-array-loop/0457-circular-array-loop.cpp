class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int i, bool fw) {
            if (fw != (nums[i] > 0)) return -1;
            int nxt = (i + nums[i]) % n;
            return (nxt < 0 ? nxt + n : nxt) == i ? -1 : (nxt < 0 ? nxt + n : nxt);
        };
        for (int i = 0; i < n; ++i) {
            if (!nums[i]) continue;
            bool fw = nums[i] > 0;
            int s = i, f = i;
            while (s != -1 && f != -1) {
                s = next(s, fw);
                f = next(f, fw);
                if (f != -1) f = next(f, fw);
                if (s != -1 && s == f) return true;
            }
            int c = i;
            while (c != -1 && next(c, fw) != -1) {
                int nxt = next(c, fw);
                nums[c] = 0;
                c = nxt;
            }
            nums[i] = 0;
        }
        return false;
    }
};