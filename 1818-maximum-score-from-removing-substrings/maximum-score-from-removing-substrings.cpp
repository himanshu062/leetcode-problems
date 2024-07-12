class Solution {
public:
    int maximumGain(string s, int x, int y) {
        return x > y ? gain(s, "ab", x, "ba", y) : gain(s, "ba", y, "ab", x);
    }

private:
    int gain(const string& s, const string& sub1, int point1,
             const string& sub2, int point2) {
        int points = 0;
        vector<char> stack1;
        vector<char> stack2;
        for (const char c : s)
            if (!stack1.empty() && stack1.back() == sub1[0] && c == sub1[1]) {
                stack1.pop_back();
                points += point1;
            } else {
                stack1.push_back(c);
            }
        for (const char c : stack1)
            if (!stack2.empty() && stack2.back() == sub2[0] && c == sub2[1]) {
                stack2.pop_back();
                points += point2;
            } else {
                stack2.push_back(c);
            }

        return points;
    }
};