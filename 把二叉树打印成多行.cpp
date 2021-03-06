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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > layer;
        if (!pRoot)
            return layer;
        TreeNode* current;
        queue<TreeNode*> queue1,queue2;
        queue<TreeNode*> *q1 = &queue1, *q2 = &queue2;
        q1->push(pRoot);
        vector<int> sub;
        sub.push_back(pRoot->val);
        layer.push_back(sub);
        while (!q1->empty()) {
            current = q1->front();
            q1->pop();
            if (current->left)
                q2->push(current->left);
            if (current->right)
                q2->push(current->right);
            if (q1->empty()) {
                vector<int> sublayer;
                while (!q2->empty()) {
                    q1->push(q2->front());
                    sublayer.push_back(q2->front()->val);
                    q2->pop();
                }
                if (sublayer.size())
                    layer.push_back(sublayer);
            }
        }
        return layer;
    }
};