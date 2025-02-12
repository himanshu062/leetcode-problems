class Solution {
public:
    static inline int digitSum(int x) {
        int sum = 0;
        for (; x > 0; x /= 10) {
            sum += x % 10;
        }
        return sum;
    }
    static int maximumSum(vector<int>& nums) {
        int maxD[82] = {0};
        int ans = -1;
        for (int x : nums) {
            int D = digitSum(x);
            if (maxD[D] > 0)
                ans = max(ans, maxD[D] + x);
            maxD[D] = max(maxD[D], x);
        }
        return ans;
    }
};