class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                revGraph[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int nei : revGraph[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};
