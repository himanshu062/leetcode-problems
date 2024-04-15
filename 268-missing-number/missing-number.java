class Solution {
    public int missingNumber(int[] nums) {
     Arrays.sort(nums);
        int n = nums.length;
        // Edge case: Handle if the smallest number in the array is not 0
        if (nums[0] != 0) {
            return 0;
        }
        // Edge case: Handle if the largest number in the array is not n
        if (nums[n - 1] != n) {
            return n;
        }
        // Iterate through the sorted array to find the missing number
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                return nums[i - 1] + 1;
            }
        }
        // If no missing number found, return -1
        return -1;   
    }
}