class Solution {
public:
    std::string generateTheString(int n) {
        
        if (n % 2 == 0) {
            return std::string(n - 1, 'a') + 'b';
        } else {
           
            return std::string(n, 'a');
        }
    }
};