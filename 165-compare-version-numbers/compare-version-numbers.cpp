class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        
        string temp = "";
        for (char c : version1) {
            if (c == '.') {
                v1.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) v1.push_back(stoi(temp));

        temp = "";
        for (char c : version2) {
            if (c == '.') {
                v2.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) v2.push_back(stoi(temp));

        // make lengths equal by padding zeros
        int n = max(v1.size(), v2.size());
        while (v1.size() < n) v1.push_back(0);
        while (v2.size() < n) v2.push_back(0);

        // compare
        for (int i = 0; i < n; i++) {
            if (v1[i] < v2[i]) return -1;
            if (v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};
