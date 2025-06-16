class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int mini = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
            if (nums[i] > mini)
                ans = max(ans, nums[i] - mini);
        }
        return ans;
    }
};