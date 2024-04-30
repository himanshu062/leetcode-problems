class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       int n = nums.size();
       int ans = 0;
       int dp =0;
       for(int i= 2;i<n;++i)
       {
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
        ans += ++dp;
        else
        dp =0;
       }
       return ans;
    }
};