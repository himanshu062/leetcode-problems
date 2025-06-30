class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer, Integer> hm = new HashMap();
        int biggest = 0;
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int x : nums) {
            hm.put(x, hm.getOrDefault(x, 0) + 1);
            min = Math.min(min, x);
            max = Math.max(max, x);
        }

        for (Integer key : hm.keySet()) {
            if (key < max && hm.containsKey(key) && hm.containsKey(key + 1))
                biggest = Math.max(biggest, hm.get(key) + hm.get(key + 1));

        }

        return biggest;
    }
}