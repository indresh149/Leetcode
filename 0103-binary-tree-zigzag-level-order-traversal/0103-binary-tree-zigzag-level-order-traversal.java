/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        List<List<Integer>> res = new LinkedList<>();
        if(root == null) return res;
        queue.add(root);
        boolean flag = false;
        while(queue.size() > 0)
        {
            int size = queue.size();
            LinkedList<Integer> subList = new LinkedList<>();
            for(int i=0;i<size;i++)
            {
                TreeNode node = queue.poll();
                if(node.left != null) queue.add(node.left);
                if(node.right != null) queue.add(node.right);
                if(flag)
                {
                    subList.addFirst(node.val);
                }
                else
                {
                    subList.addLast(node.val);
                }
            }
            flag = !flag;
            res.add(subList);
        }
        return res;
    }
}