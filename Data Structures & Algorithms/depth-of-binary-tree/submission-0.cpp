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
    int f(TreeNode* root){
        if(root==NULL)return 0;

        int rh=0;
        if(root->right){
            rh=f(root->right);
        }
        int lt=0;
        if(root->left){
            lt=f(root->left);
        }
        return 1+max(lt,rh);
    }

    int maxDepth(TreeNode* root) {
        return f(root);
    }
};
