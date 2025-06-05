class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int uu = findUPar(u);
        int uv = findUPar(v);
        if (uu == uv) return;
        // always attach the lex smaller to the larger one
        if (uu < uv) {
            parent[uv] = uu;
        } else {
            parent[uu] = uv;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26); // 26 lowercase letters

        for (int i = 0; i < s1.length(); ++i) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            ds.unionByRank(u, v);
        }

        string res = "";
        for (char c : baseStr) {
            int parent = ds.findUPar(c - 'a');
            res += (char)(parent + 'a');
        }
        return res;
    }
};
