# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_res = root.val

        def post_ord(node):
            nonlocal max_res
            if node == None:
                return 0
            
            left = post_ord(node.left)
            right = post_ord(node.right)
            max_res = max(max_res, node.val+left+right)
            path = node.val+max(left, right)
            return max(0, path)
        
        post_ord(root)
        return max_res
