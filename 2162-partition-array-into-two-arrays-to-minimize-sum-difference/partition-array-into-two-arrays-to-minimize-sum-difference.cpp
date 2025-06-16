class Solution {
public:
    vector<vector<int>> rec1, rec2;
    vector<int> arr;

    void f(int index, int len, int sum, int e, vector<vector<int>>& rec) {
        if (index >= e) {
            rec[len].push_back(sum);
            return;
        }

        // take
        f(index + 1, len + 1, sum + arr[index], e, rec);

        // not take
        f(index + 1, len, sum, e, rec);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        arr = nums;

        rec1.resize(n / 2 + 1);
        rec2.resize(n / 2 + 1);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        f(0, 0, 0, n / 2, rec1);
        f(n / 2, 0, 0, n, rec2);

        for (int i = 0; i <= n / 2; ++i) {
            sort(rec2[i].begin(), rec2[i].end());
        }

        int ans = INT_MAX;

        for (int i = 0; i <= n / 2; ++i) {
            vector<int>& temp = rec2[n / 2 - i];
            for (int sum1 : rec1[i]) {
                int target = totalSum / 2 - sum1;
                auto it = lower_bound(temp.begin(), temp.end(), target);

                if (it != temp.end()) {
                    int sum = sum1 + *it;
                    ans = min(ans, abs(totalSum - 2 * sum));
                }

                if (it != temp.begin()) {
                    --it;
                    int sum = sum1 + *it;
                    ans = min(ans, abs(totalSum - 2 * sum));
                }
            }
        }

        return ans;
    }
};