class Solution {
public:
    static long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1=0, s2=0;
        int z1=0, z2=0;
        for(int x: nums1){
            s1+=x;
            z1+=x==0;
        }
        for(int x: nums2){
            s2+=x;
            z2+=x==0;
        }
        if ((z1==0 && s1<s2+z2)||(z2==0 && s2<s1+z1))
            return -1;
        return max(s1+z1, s2+z2);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();