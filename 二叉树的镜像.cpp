/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    TreeNode *MirrorTree(TreeNode *root) {
        if (!root)
            return NULL;
        TreeNode *left = root->left;
        root->left = MirrorTree(root->right);
        root->right = MirrorTree(left);
        return root;
    }
    void Mirror(TreeNode *pRoot) {
        MirrorTree(pRoot);
    }
};