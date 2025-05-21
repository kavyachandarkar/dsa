class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums.size() != 3) {
            return "none";
        }

        int a = nums[0], b = nums[1], c = nums[2];

        // Check for triangle validity using triangle inequality
        if (a + b <= c || b + c <= a || a + c <= b) {
            return "none";
        }

        if (a == b && b == c) {
            return "equilateral";
        } else if (a == b || b == c || a == c) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};
