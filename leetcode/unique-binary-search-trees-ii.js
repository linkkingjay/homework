/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function(n) {
  function func(min, max) {
    var trees = [];
    if (min > max) {
      trees.push(null);
      return trees;
    }

    var i, lIndex, rIndex, left, right;
    for (i = min; i <= max; i++) {
      left = func(min, i - 1);
      right = func(i + 1, max);
      for (lIndex = 0; lIndex < left.length; lIndex++) {
        for (rIndex = 0; rIndex < right.length; rIndex++) {
          trees.push((function () {
            var node = new TreeNode(i);
            node.left = left[lIndex];
            node.right = right[rIndex];
            return node;
          })());
        }
      }
    }

    return trees;
  }

  return func(1, n);
};

console.log(generateTrees(1));

function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}
