class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        int able = 0;

        ranges::sort(nums);

        for (const int num : nums) {
            ans += max(able - num, 0);
            able = max(able, num) + 1;
        }

        return ans;
    }
};