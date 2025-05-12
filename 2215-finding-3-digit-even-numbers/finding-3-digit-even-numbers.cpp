class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {
        set<int> seen;  // To avoid duplicates
        int n = d.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k) continue;

                    int a = d[i], b = d[j], c = d[k];

                    if (a == 0) continue;         
                    if (c % 2 != 0) continue;     

                    int num = a * 100 + b * 10 + c;
                    seen.insert(num);
                }
            }
        }

        vector<int> ans(seen.begin(), seen.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
