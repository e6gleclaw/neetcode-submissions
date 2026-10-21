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
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val || root->val==q->val)return root;

        TreeNode* lh=NULL;
        TreeNode* rh=NULL;
        lh=f(root->left,p,q);
        rh=f(root->right,p,q);
        if(lh==NULL && rh)return rh;
        if(rh==NULL && lh)return lh;
        if(lh && rh)return root;
        return NULL;
    }   

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};
