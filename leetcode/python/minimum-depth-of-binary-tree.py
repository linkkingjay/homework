# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def minDepth(self, root):
        if root == None:
            return 0
        if root.left or root.right:
            leftDepth = 1 + self.minDepth(root.left)
            rightDepth = 1 + self.minDepth(root.right)
            if root.left == None:
                return rightDepth
            elif root.right == None:
                return leftDepth
            else:
                return min(leftDepth, rightDepth)
        else:
            return 1
