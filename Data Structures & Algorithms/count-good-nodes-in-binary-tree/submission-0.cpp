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
    void traverse(TreeNode* root, int &count, int max){
        if(root == NULL) {
            return;
        }

        if(root->left){
            if(root->left->val>=max){
                count++;
                traverse(root->left, count, root->left->val);
            }
            else {
                traverse(root->left, count, max);
            }
            
        }

        if(root->right){
            if(root->right->val>=max){
                count++;
                traverse(root->right,count,root->right->val);
            }
            else {
                traverse(root->right,count,max);
            }
            
        }
        return;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count = 1;
        traverse(root,count,root->val);
        return count;
    }
};
