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
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot)
            return 0;
        int length = TreeDepth(pRoot->left);
        int rLength = TreeDepth(pRoot->right);
        if (rLength > length)
            length = rLength;
        return length + 1;
    }
};