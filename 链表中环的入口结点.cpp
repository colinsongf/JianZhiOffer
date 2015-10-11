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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* target = NULL, *onestep, *twostep;
        onestep = twostep = pHead;
        do {
            onestep = onestep->next;
            twostep = twostep->next;
            if (twostep)
                twostep = twostep->next;
            else
                return NULL;
        } while(onestep && twostep && onestep != twostep);
        if (!onestep || !twostep)
            return NULL;
        target = onestep;
        while (pHead != target) {
            pHead = pHead->next;
            target = target->next;
        }
        return target;
    }
};