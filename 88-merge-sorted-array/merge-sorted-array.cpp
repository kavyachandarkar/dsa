#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        vector<int> ans;
        ans.insert(ans.end(), num1.begin(), num1.begin() + m);

        ans.insert(ans.end(), num2.begin(), num2.begin() + n);

        sort(ans.begin(), ans.end());

        for (int i = 0; i < m + n; i++) {
            num1[i] = ans[i];
        }

        for (int i = 0; i < m + n; i++) {
            cout << num1[i] << " ";  
        }
        cout << endl;
    }
};


