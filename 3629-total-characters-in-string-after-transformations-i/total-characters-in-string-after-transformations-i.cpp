class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> count(26, 0);
        for (char ch : s) {
            count[ch - 'a']++;
        }

        while (t--) {
            vector<long long> next(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (i == 25) {
                    next[0] = (next[0] + count[25]) % MOD;
                    next[1] = (next[1] + count[25]) % MOD;
                } else {
                    next[i + 1] = (next[i + 1] + count[i]) % MOD;
                }
            }
            count = next;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + count[i]) % MOD;
        }
        return result;
    }
};
