
/**
 * @param {TreeNode} root
 * @return {number}
 */
var deepestLeavesSum = function (root) {
    return sumDeepestLeaves(root, maxHeight(root));
};


/**
 * @param {TreeNode} root
 * @param {number} height
 * @return {number}
 */
function sumDeepestLeaves(root, height) {
    if (root === null) {
        return 0;
    }
    if (height === 1) {
        return root.val;
    }
    let sum = sumDeepestLeaves(root.left, height - 1) + sumDeepestLeaves(root.right, height - 1);
    return sum;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
function maxHeight(root) {
    if (root === null) {
        return 0;
    }
    let max = Math.max(maxHeight(root.left) + 1, maxHeight(root.right) + 1);
    return max;
}

/*
 Function TreeNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}
