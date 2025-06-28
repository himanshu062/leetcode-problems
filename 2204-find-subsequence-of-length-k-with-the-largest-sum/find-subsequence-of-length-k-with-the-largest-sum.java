class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        List<int[]> pairs = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            pairs.add(new int[] { nums[i], i });
        }
        pairs.sort((a, b) -> Integer.compare(b[0], a[0]));
        List<int[]> topK = new ArrayList<>(pairs.subList(0, k));
        topK.sort((a, b) -> Integer.compare(a[1], b[1]));
        int result[] = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = topK.get(i)[0];
        }
        return result;
    }
}