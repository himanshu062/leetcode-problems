class Solution {
    static public String clearStars(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        StringBuilder sb = new StringBuilder();
        boolean[] removed = new boolean[n];
        Stack<Integer>[] stacks = new Stack[26];
        for (int i = 0; i < 26; i++)
            stacks[i] = new Stack<>();

        for (int i = 0; i < n; i++) {
            char c = arr[i];
            if (c == '*') {
                removeStar(removed, stacks);
            } else {
                stacks[c - 'a'].push(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!removed[i] && arr[i] != '*')
                sb.append(arr[i]);
        }
        return sb.toString();
    }

    static void removeStar(boolean[] removed, Stack<Integer>[] stacks) {
        for (int i = 0; i < 26; i++) {
            if (!stacks[i].isEmpty()) {
                removed[stacks[i].pop()] = true;
                return;
            }
        }
    }
}