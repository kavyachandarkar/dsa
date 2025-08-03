class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int longest_streak = 1;
        int current_streak = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    current_streak += 1;
                } else {
                    longest_streak = std::max(longest_streak, current_streak);
                    current_streak = 1;
                }
            }
        }

        return std::max(longest_streak, current_streak);
    }
};