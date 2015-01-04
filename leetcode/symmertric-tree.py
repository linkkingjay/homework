# Definition for a binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isSymmetric(self, root):
        if root is None:
            return True
        return self.isMirror(root.left, root.right)

    def isMirror(self, x, y):
        if x is None and y is not None:
            return False
        if x is not None and y is None:
            return False
        if x is None and y is None:
            return True

        return x.val == y.val and self.isMirror(x.left, y.right) and self.isMirror(x.right, y.left)
