class Solution {
public:
    string robotWithString(string s) {
        string ans = "";
        string t = "";
        
        unordered_map<char, int> frq;
        for (char c : s) {
            frq[c]++;
        }

        char sml = 'a';

        for (char c : s) {
            if (c == sml) {
                ans += c;
            } 
            else {
                t.push_back(c);
            }

            frq[c]--;
            if (frq[c] == 0) {
                frq.erase(c);
            }

            while (sml <= 'z' && frq.count(sml) == 0) {
                sml++;
            }

            while (!t.empty() && t.back() <= sml) {
                ans += t.back();
                t.pop_back();
            }
        }

        while (!t.empty()) {
            ans += t.back();
            t.pop_back();
        }

        return ans;
    }
};