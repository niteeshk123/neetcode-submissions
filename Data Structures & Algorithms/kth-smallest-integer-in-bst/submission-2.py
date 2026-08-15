# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.res = 0
        self.k = 0
    
    def kthSmallestUtil(self, root: Optional[TreeNode]):
        if root is None:
            return
        if root.left:
            self.kthSmallestUtil(root.left)
        self.k-=1
        if self.k==0:
            self.res = root.val
        if root.right:
            self.kthSmallestUtil(root.right)
        return

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.k = k
        self.kthSmallestUtil(root)
        return self.res
        
        

        