
class Solution {
public:
    bool f(TreeNode* p, TreeNode* q) {
        // Both nodes are NULL
        if (p == NULL && q == NULL)
            return true;

        // Only one node is NULL
        if (p == NULL || q == NULL)
            return false;

        // Compare current node values
        if (p->val != q->val)
            return false;

        // Both left and right subtrees must be identical
        return f(p->left, q->left) &&
               f(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return f(p, q);
    }
};
