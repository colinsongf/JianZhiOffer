/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* pHead,*prev;
        if (pHead1 && pHead2) {
            pHead = pHead1->val <= pHead2->val ? pHead1 : pHead2;
            if (pHead1->val <= pHead2->val) {
                pHead1 = pHead1->next;
            } else {
                pHead2 = pHead2->next;
            }
        } else if (pHead1) {
            return pHead1;
        } else {
            return pHead2;
        }
        prev = pHead;
        while (pHead1 && pHead2) {
            prev->next = pHead1->val <= pHead2->val ? pHead1 : pHead2;
            prev = prev->next;
            if (pHead1->val <= pHead2->val) {
                pHead1 = pHead1->next;
            } else {
                pHead2 = pHead2->next;
            }
        }
        prev->next = pHead1 ? pHead1 : pHead2;
        return pHead;
    }
};