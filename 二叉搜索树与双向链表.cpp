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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* root = ConvertMid(pRootOfTree);
        if (root) {
            while (root->left)
                root = root->left;
        }  
        return root;
    }  
    TreeNode* ConvertMid(TreeNode* pRootOfTree) {
        if (!pRootOfTree)
            return NULL;
        TreeNode* left = ConvertMid(pRootOfTree->left);
        TreeNode* right = ConvertMid(pRootOfTree->right);
        if (left) {
            while (left->right)
                left = left->right;
            left->right = pRootOfTree;
        }  
        pRootOfTree->left = left;
        if (right) {
            while (right->left)
                right = right->left;
            right->left = pRootOfTree;
        }  
        pRootOfTree->right = right;
        return pRootOfTree;
    }  
};