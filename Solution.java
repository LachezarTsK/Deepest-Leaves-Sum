
public class Solution {

    public int deepestLeavesSum(TreeNode root) {
        return sumDeepestLeaves(root, maxHeight(root));
    }

    private int sumDeepestLeaves(TreeNode root, int height) {
        if (root == null) {
            return 0;
        }
        if (height == 1) {
            return root.val;
        }
        int sum = sumDeepestLeaves(root.left, height - 1) + sumDeepestLeaves(root.right, height - 1);
        return sum;
    }

    private int maxHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int max = Math.max(maxHeight(root.left) + 1, maxHeight(root.right) + 1);
        return max;
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(){}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
