class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;
        
        // Union each row and column (shift col to differentiate from row)
        for (auto& stone : stones) {
            int row = stone[0], col = stone[1] + 10001;
            unite(row, col, parent);
        }
        
        unordered_set<int> unique_roots;
        for (auto& stone : stones) {
            unique_roots.insert(find(stone[0], parent));
        }
        
        return stones.size() - unique_roots.size();  // Max stones removable
    }

private:
    int find(int x, unordered_map<int, int>& parent) {
        if (parent.find(x) == parent.end())
            parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int a, int b, unordered_map<int, int>& parent) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA != rootB)
            parent[rootA] = rootB;
    }
};
