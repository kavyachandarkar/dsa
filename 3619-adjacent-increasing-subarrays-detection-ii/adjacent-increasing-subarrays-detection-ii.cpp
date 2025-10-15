class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int prev = 0, curr = 1, k = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                curr++;
            } else {
                prev = curr;
                curr = 1;
            }
            k = max(k, min(prev, curr));
            k = max(k, curr / 2);
        }
        return k;
    }
};
