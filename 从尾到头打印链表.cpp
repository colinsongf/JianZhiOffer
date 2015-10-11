/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    void printListReverse(vector<int>& answer, struct ListNode* head) {
        if (!head)
            return ;
        printListReverse(answer, head->next);
        answer.push_back(head->val);
    }
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> answer;
        printListReverse(answer, head);
        return answer;
    }
};