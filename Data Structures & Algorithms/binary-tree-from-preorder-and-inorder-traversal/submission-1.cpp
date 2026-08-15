/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int idx = 0;
    TreeNode *construct(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> inmap, int i, int j){
        if(i<0 || i>j){
            return NULL;
        }

        TreeNode *node = new TreeNode(preorder[idx++]);
        int node_i = inmap[node->val];
        node->left = construct(preorder, inorder, inmap, i, node_i-1); 
        node->right = construct(preorder, inorder, inmap, node_i+1, j); 

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inmap;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inmap[inorder[i]] = i;
        }

        TreeNode *head = construct(preorder, inorder, inmap, 0, n-1);
        return head;
    }
};
