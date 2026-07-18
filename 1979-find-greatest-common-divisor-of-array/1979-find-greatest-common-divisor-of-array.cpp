#include <vector>

class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    int findGCD(std::vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];
        
        for (int num : nums) {
            if (num < mn) mn = num;
            if (num > mx) mx = num;
        }
        
        return gcd(mn, mx);
    }
};