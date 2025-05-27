class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);  // Initialize each node to itself

        int extra = 0;
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            if (find(u, parent) != find(v, parent)) {
                unite(u, v, parent, rank);
            } else {
                extra++; // Redundant cable
            }
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i, parent) == i) {
                components++;
            }
        }

        int needed = components - 1;
        return (extra >= needed) ? needed : -1;
    }

private:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);  // Path compression
        }
        return parent[x];
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);
        if (a == b) return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else if (rank[b] < rank[a]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
};
