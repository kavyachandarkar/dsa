class Solution {
public:
    std::string generateTheString(int n) {
        std::string ans = "";
        
        if (n % 2 == 0) {
           
            ans.push_back('a'); 
            for (int i = 0; i < n - 1; ++i) {
                ans.push_back('b'); 
            }
        } else {
           
            for (int i = 0; i < n; ++i) {
                ans.push_back('a');
            }
        }
        
        return ans;
    }
};
