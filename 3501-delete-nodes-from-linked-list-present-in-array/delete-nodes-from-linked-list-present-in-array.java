class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        int max = -1;
        for (int num : nums)
            max = Math.max(max, num);
        boolean[] freq = new boolean[max + 1];

        for (int num : nums)
            freq[num] = true;

        ListNode temp = new ListNode();
        ListNode curr = temp;

        while (head != null) {
            if (head.val >= freq.length || freq[head.val] == false) {
                curr.next = head;
                curr = curr.next;
            }

            head = head.next;
        }

        curr.next = null;
        return temp.next;
    }
}