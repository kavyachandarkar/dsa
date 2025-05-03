class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>>adj(num);
        vector<int>inorder(num,0);

        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0 ; i<num ;  i++){
            for(auto it: adj[i]){
                inorder[it]++;
            }
        }
         
        queue<int>q;
        for(int i=0 ;i<num ;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                }
            }
         
        }
        if(topo.size()==num)return topo;
        else return {} ;
    }
};