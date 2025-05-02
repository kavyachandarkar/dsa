class Solution {
public:
    string pushDominoes(string d) {
        int j = 0;
        for (int i = 0; i < d.size(); i++) {
            if (d[i] == '.') {
                int start = i;
                do {
                    i++;
                } while (i < d.size() && d[i] == '.');
                int end = i;

                char left = (start - 1 >= 0) ? d[start - 1] : '.';
                char right = (i < d.size()) ? d[i] : '.';

                if (left == 'R' && right == 'L') {
                    // balance
                    int l = start, r = i - 1;
                    while (l < r) {
                        d[l++] = 'R';
                        d[r--] = 'L';
                    }
                }
                else if (left == 'R') {
                    for (int k = start; k < end; k++) d[k] = 'R';
                }
                else if (right == 'L') {
                    for (int k = start; k < end; k++) d[k] = 'L';
                }
            }
        }
        return d;
    }
};
