class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;   // total subarrays
        long long streak = 0; // current consecutive zeros

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                streak++;            // extend zero streak
                cnt += streak;       // add subarrays ending at i
            } else {
                streak = 0;          // reset when non-zero
            }
        }
        return cnt;
    }
};
