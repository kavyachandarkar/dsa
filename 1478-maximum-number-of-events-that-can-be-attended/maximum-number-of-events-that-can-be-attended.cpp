class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int, vector<int>, greater<int>> p;
        int n = events.size();
        int cnt=0;
        int d=events[0][0];
        int i=0;
        while(i<n || !p.empty()){
            while(i<n && events[i][0]==d){
                p.push(events[i][1]);
                i++;
            }
            if(!p.empty()){
                p.pop();
                cnt++;
            }
            d++;
            while(!p.empty() && p.top()<d ){
                p.pop();
            }
        }
        return cnt;
    }
};