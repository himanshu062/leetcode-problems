class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            int ans = nums[i]^nums[i+1];
            if(ans==0)
            return nums[i];
        }
        return -1;
    }
};