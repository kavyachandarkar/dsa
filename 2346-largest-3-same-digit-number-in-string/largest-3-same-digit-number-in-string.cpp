#include <string>
#include <algorithm> // Required for std::max

class Solution {
public:
    std::string largestGoodInteger(std::string num) {
        std::string best = "";
        // Your loop condition is perfect.
        for (int i = 0; i + 2 < num.size(); i++) {
            // Your check is also perfect.
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                // This is the C++ way to do exactly what you intended.
                best = std::max(best, num.substr(i, 3));
            }
        }
        return best;
    }
};