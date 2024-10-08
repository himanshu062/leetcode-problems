class Solution {
public:
    int minSwaps(string s) {
        int unmatched = 0;

        for (const char c : s)
            if (c == '[')
                ++unmatched;
            else if (unmatched > 0) 
                --unmatched;

        return (unmatched + 1) / 2;
    }
};