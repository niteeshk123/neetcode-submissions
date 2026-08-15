# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.prevValue = -10e9

    def Inorder(self, root):
        if root is None:
            return True
        
        if not self.Inorder(root.left):
            return False
        if self.prevValue>=root.val:
            return False
        self.prevValue=root.val
        return self.Inorder(root.right)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.Inorder(root)