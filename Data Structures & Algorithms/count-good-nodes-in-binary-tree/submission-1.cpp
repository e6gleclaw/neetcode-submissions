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
    void f(TreeNode* root,vector<int>& ans,int ele){
        if(root==NULL)return;

        if(root->val>=ele){
            ans.push_back(root->val);
            ele=root->val;
        }
        f(root->left,ans,ele);
        f(root->right,ans,ele);
    }
    int goodNodes(TreeNode* root) {
        vector<int>ans;
        f(root,ans,INT_MIN);
        return ans.size();
    }
};
