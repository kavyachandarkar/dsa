class DisjointSet {
public:
    vector<int> rank, parent;

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
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailToIndex;

        // Step 1: Merge accounts using DSU
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailToIndex.find(mail) == mailToIndex.end()) {
                    mailToIndex[mail] = i;
                } else {
                    ds.unionByRank(i, mailToIndex[mail]);
                }
            }
        }

        // Step 2: Group mails by parent index
        unordered_map<int, vector<string>> mergedAccounts;
        for (auto& it : mailToIndex) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedAccounts[node].push_back(mail);
        }

        // Step 3: Create the final merged result
        vector<vector<string>> ans;
        for (auto& it : mergedAccounts) {
            int index = it.first;
            vector<string> mails = it.second;
            sort(mails.begin(), mails.end());
            vector<string> temp;
            temp.push_back(accounts[index][0]); // Add the name
            temp.insert(temp.end(), mails.begin(), mails.end());
            ans.push_back(temp);
        }

        return ans;
    }
};
