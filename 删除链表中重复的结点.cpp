/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead || !pHead->next)
            return pHead;
        ListNode *prev = NULL, *newpHead = NULL;
        int dup;
        while (pHead) {
            if (!pHead->next || pHead->val != pHead->next->val) {
                if (!prev) {
                    newpHead = pHead;
                } else {
                    prev->next = pHead;
                }
                prev = pHead;
                pHead = pHead->next;
            } else {//pHead->val = pHead->next->val
                dup = pHead->val;
                while (pHead && pHead->val == dup) {
                    pHead = pHead->next;
                }
            }
        }
        if (prev)
            prev->next = NULL;
        return newpHead;
    }
};