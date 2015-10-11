/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :Prin
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> answer;
        if (!root)
            return answer;
        queue<TreeNode *> q;
        TreeNode* cur;
        q.push(root);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            answer.push_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        return answer;
    }
};