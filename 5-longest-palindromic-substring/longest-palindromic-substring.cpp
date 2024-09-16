class Solution {
public:
    string longestPalindrome(string s) {
        const string& t = join('@' + s + '$', '#');
        const int n = t.length();
        vector<int> maxExtends(n);
        int center = 0;
        for (int i = 1; i < n - 1; ++i) {
            const int rightBoundary = center + maxExtends[center];
            const int mirrorIndex = center - (i - center);
            maxExtends[i] = rightBoundary > i &&
                            min(rightBoundary - i, maxExtends[mirrorIndex]);
            while (t[i + 1 + maxExtends[i]] == t[i - 1 - maxExtends[i]])
                ++maxExtends[i];
            if (i + maxExtends[i] > rightBoundary)
                center = i;
        }
        int maxExtend = 0;
        int bestCenter = -1;
        for (int i = 0; i < n; ++i)
            if (maxExtends[i] > maxExtend) {
                maxExtend = maxExtends[i];
                bestCenter = i;
            }

        const int l = (bestCenter - maxExtend) / 2;
        const int r = (bestCenter + maxExtend) / 2;
        return s.substr(l, r - l);
    }

private:
    string join(const string& s, char c) {
        string joined;
        for (int i = 0; i < s.length(); ++i) {
            joined += s[i];
            if (i != s.length() - 1)
                joined += c;
        }
        return joined;
    }
};