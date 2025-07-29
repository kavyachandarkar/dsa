class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> last_set_bit(32,-1);
        vector<int> ans(n);
        for(int l = n-1;l>=0;l--){
            for(int bit = 0;bit < 32;bit++){
                if(nums[l] & (1<<bit)){
                    last_set_bit[bit] = l;
                }
            }
            int r = l;
            for(int bit = 0;bit < 32;bit++){
                if(last_set_bit[bit] != -1){
                    r = max(r,last_set_bit[bit]);
                }
            }
            ans[l] = r-l+1;
        }
        return ans;
    }
};