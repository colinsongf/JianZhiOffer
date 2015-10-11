/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* originRoot, TreeNode* isoRoot) {
        if (!originRoot && !isoRoot)
            return true;
        if (!originRoot || !isoRoot || originRoot->val != isoRoot->val)
            return false;
        return isSymmetrical(originRoot->left, isoRoot->right) && isSymmetrical(originRoot->right, isoRoot->left);
    }
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot)
            return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }
};