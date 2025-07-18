class Solution {
    public long minimumDifference(int[] nums) {
        int n = nums.length / 3;
        long[] A_sum = new long[3 * n + 1];
        long[] B_sum = new long[3 * n + 1];

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            maxHeap.offer(nums[j]);
        }
        A_sum[n] = sum;

        for (int i = n + 1; i <= 2 * n; i++) {
            int x = nums[i - 1];
            if (x < maxHeap.peek()) {
                sum = sum - maxHeap.poll() + x;
                maxHeap.offer(x);
            }
            A_sum[i] = sum;
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        sum = 0;
        for (int j = 2 * n; j < 3 * n; j++) {
            sum += nums[j];
            minHeap.offer(nums[j]);
        }
        B_sum[2 * n] = sum;

        for (int i = 2 * n - 1; i >= n; i--) {
            int x = nums[i];
            if (x > minHeap.peek()) {
                sum = sum - minHeap.poll() + x;
                minHeap.offer(x);
            }
            B_sum[i] = sum;
        }

        long ans = Long.MAX_VALUE;
        for (int i = n; i <= 2 * n; i++) {
            ans = Math.min(ans, A_sum[i] - B_sum[i]);
        }
        return ans;
    }
}