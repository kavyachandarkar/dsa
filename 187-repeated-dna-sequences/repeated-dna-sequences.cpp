class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n= s.size();
        unordered_map<string,int>mpp;
        for(int i=0 ;i<n-9;i++){
            mpp[s.substr(i,10)]++;
        }
        vector<string>ans;
        for(auto el:mpp){
            if(el.second>1)ans.push_back(el.first);
        }
        return ans;
    }
};