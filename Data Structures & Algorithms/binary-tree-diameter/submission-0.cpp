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
    int f(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int rh=0;
        if(root-> right){
            rh=f(root->right,ans);
        }
        int lh=0;
        if(root-> left){
            lh=f(root->left,ans);
        }
        ans=max(ans,lh+rh);
        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};
