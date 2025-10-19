
class Solution {
public:
    string rotate(string s, int b){
        int n = s.size();
        b %= n;
        string first = s.substr(0, n - b);
        string last = s.substr(n - b, b);
        return last + first;
    }

    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string mini = s;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            mini = min(mini, node);

            string rotated_node = rotate(node, b);
            if (vis.find(rotated_node) == vis.end()) {
                vis.insert(rotated_node);
                q.push(rotated_node);
            }

            string up = node;
            for (int i = 1; i < n; i += 2) {
                int val = up[i] - '0';
                val = (val + a) % 10;
                up[i] = val + '0';
            }
            if (vis.find(up) == vis.end()) {
                vis.insert(up);
                q.push(up);
            }
        }
        return mini;
    }
};
