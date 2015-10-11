class Solution {
public:
    int diff(int a, int b) {
        return a > b ? a - b : b - a;
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
    bool IsBalanced(TreeNode* pRoot, int *hp) {
        if (!pRoot) {
            *hp = 0;
            return true;
        }
        int lh = 0, rh = 0;
        bool status = (IsBalanced(pRoot->left, &lh) && IsBalanced(pRoot->right, &rh) && diff(lh, rh) <= 1);
        *hp = max(lh, rh) + 1;
        return status;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int height;
        return IsBalanced(pRoot, &height);
    }
};