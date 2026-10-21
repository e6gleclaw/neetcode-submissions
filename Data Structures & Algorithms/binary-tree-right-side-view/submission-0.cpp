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
    vector<int> rightSideView(TreeNode* root) {
        map<int,TreeNode*>mp;
        vector<int>ans;
        if(root==NULL)return ans;
        mp[0]=root;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(!q.empty()){
            int lev=q.front().first;
            TreeNode* temp=q.front().second;
            q.pop();
            if(temp->left){
                q.push({lev+1,temp->left});
                mp[lev+1]=temp->left;
            }
            if(temp->right){
                q.push({lev+1,temp->right});
                mp[lev+1]=temp->right;
            }
        }
        for(auto ele:mp){
            ans.push_back(ele.second->val);
        }
        return ans;
    }
};
