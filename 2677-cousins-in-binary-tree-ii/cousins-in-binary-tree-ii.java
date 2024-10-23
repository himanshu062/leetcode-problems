/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public TreeNode replaceValueInTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int prevSum = root.val;
        while (!queue.isEmpty()) {
            int size = queue.size();
            int curSum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                node.val = prevSum - node.val;
                int sibsum = 0;
                if (node.left != null)
                    sibsum += node.left.val;

                if (node.right != null)
                    sibsum += node.right.val;

                if (node.left != null) {
                    curSum += node.left.val;
                    node.left.val = sibsum;
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    curSum += node.right.val;
                    node.right.val = sibsum;
                    queue.offer(node.right);
                }
            }
            prevSum = curSum;
        }
        return root;
    }
}