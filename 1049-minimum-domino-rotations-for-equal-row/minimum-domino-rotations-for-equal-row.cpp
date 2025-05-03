class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> mpp;
        unordered_map<int, int> mpp2;
        int cnt = 0;
        int cnt2 = 0;
        int maxi = 0;
        int maxi2 = 0;
        int number = -1;

        for (int i = 0; i < tops.size(); i++) {
            mpp[tops[i]]++;
            mpp2[bottoms[i]]++;
            
            if (mpp[tops[i]] > maxi) {
                maxi = mpp[tops[i]];
                number = tops[i];
            }
            
            if (mpp2[bottoms[i]] > maxi2) {
                maxi2 = mpp2[bottoms[i]];
                number = bottoms[i];
            }
        }

        if (maxi > maxi2) {
            for (int i = 0; i < tops.size(); i++) {
                if (tops[i] != number) {
                    if (bottoms[i] == number) {
                        cnt++;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            for (int i = 0; i < bottoms.size(); i++) {
                if (bottoms[i] != number) {
                    if (tops[i] == number) {
                        cnt++;
                    } else {
                        return -1;
                    }
                }
            }
        }
        return cnt;
    }
};
