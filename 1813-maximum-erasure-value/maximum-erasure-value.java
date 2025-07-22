class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int left = 0, right = 0, sum = 0, maxSum = 0;

        while (right < nums.length) {
            if (!set.contains(nums[right])) {
                set.add(nums[right]);
                sum += nums[right];
                maxSum = Math.max(maxSum, sum);
                right++;
            } else {
                set.remove(nums[left]);
                sum -= nums[left];
                left++;
            }
        }

        return maxSum;
    }
}