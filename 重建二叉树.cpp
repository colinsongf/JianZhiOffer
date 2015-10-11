/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTreeR(vector<int> pre, int phead, int prear, vector<int> in, int ihead, int irear) {
        cout << phead << "-" << prear << "-" << ihead << "-" << irear << endl;
        if (phead >= prear || ihead >= irear)
            return NULL;
        struct TreeNode* root = new TreeNode(pre[phead]);
        int isplit;
        for (isplit = ihead; isplit < irear && in[isplit] != pre[phead]; ++isplit);
        int leftSubTreeSize = isplit - ihead;
        root->left = reConstructBinaryTreeR(pre, phead + 1, phead + 1 + leftSubTreeSize, in, ihead, isplit);
        root->right = reConstructBinaryTreeR(pre, phead + 1 + leftSubTreeSize, prear, in, isplit + 1, irear);
        return root;
    }
    struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        return reConstructBinaryTreeR(pre, 0, pre.size(), in, 0, in.size());
    }
};