# Definition of a binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        if root == None:
            return 0

        if root.left or root.right:
            return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
        else:
            return 0
