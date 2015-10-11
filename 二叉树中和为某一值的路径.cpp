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
    void FindPathR(TreeNode* root, vector<int> subanswer, int expectNumber, int currentNumber) {
        if (!root)
            return ;
        currentNumber += root->val;
        subanswer.push_back(root->val);
        if (!root->left && !root->right) {
            if (currentNumber == expectNumber) {
                answer.push_back(subanswer);
            }  
        }  
        FindPathR(root->left, subanswer, expectNumber, currentNumber);
        FindPathR(root->right, subanswer, expectNumber, currentNumber);
    }  
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<int> subanswer;
        FindPathR(root, subanswer, expectNumber, 0);
        return answer;
    }  
private:
    vector<vector<int> > answer;
};