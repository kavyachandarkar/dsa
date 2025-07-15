class Solution {
public:
    bool isValid(string word) {
        if (word.size() > 2)
        {
            bool flag1 = 1;
            int flag2 = 0;
            int flag3 = 0;
            for (char c : word)
            {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') flag2++;
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') flag2++;
                if (c >= '0' && c <= '9') flag3++;
                if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) continue;
                else
                {
                    flag1 = 0;
                }
            }
            if (flag1 && flag2 && (word.size() - flag2 - flag3)) return 1;
            else return 0;
        }
        return 0;
    }
};