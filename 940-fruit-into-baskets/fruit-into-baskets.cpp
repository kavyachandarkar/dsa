class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=-1;
        int sl=-1, lc=0 ,cur=0 ,maxi=0;
        
        for(int fruit : fruits){
           if(fruit == l || fruit == sl){
            cur++;
           }
           else{
            cur= lc+1;
           }
           if(fruit == l){
            lc++;
           }else{
            lc=1;
            sl=l;
            l=fruit;
           }
            maxi=max(maxi, cur);
        }
         return maxi;   
        
    }
};