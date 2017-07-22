/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
  if (nums.length > 0) {
    var i = parseInt(nums.length / 2)
    var tree = new TreeNode(nums[i])

    tree.left = sortedArrayToBST(nums.slice(0, i))
    tree.right = sortedArrayToBST(nums.slice(i + 1))

    return tree
  } else {
    return null
  }
};
