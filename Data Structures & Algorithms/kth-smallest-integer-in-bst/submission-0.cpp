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
    void kthsmallutil(TreeNode* root, int k, int *index, int *res){
        if(root==NULL){
            return;
        }
        kthsmallutil(root->left, k, index, res);
        if(*index == (k - 1)){
            *res = root->val;
        }
        (*index)++;
        kthsmallutil(root->right, k, index, res);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int index = 0;
        kthsmallutil(root, k, &index, &res);

        return res;
    }
};
