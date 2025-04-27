class Solution {
    public int countSubarrays(int[] nums) {
        int n = nums.length;
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == 2 * (nums[i - 1] + nums[i + 1])) {
                count++;

            }
        }
        return count;
    }
}