# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def utility(self, root, level, res):
        if root is None:
            return
        
        if level>=len(res):
            res.append([])
        res[level].append(root.val)

        self.utility(root.left, level+1, res)
        self.utility(root.right, level+1, res)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        self.utility(root, 0, res)
        return res