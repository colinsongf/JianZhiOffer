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
    unsigned int ListLength(ListNode *pHead) {
        unsigned int length = 0;
        while (pHead) {
            pHead = pHead->next;
            ++length;
        }
        return length;
    }
    ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        unsigned int length1 = ListLength(pHead1);
        unsigned int length2 = ListLength(pHead2);
        unsigned int diff = length1 > length2 ? length1 - length2 : length2 - length1;
        unsigned int i = 0;
        if (length1 > length2)
            while (i++ < diff)
                pHead1 = pHead1->next;
        else
            while (i++ < diff)
                pHead2 = pHead2->next;
        while (pHead1 && pHead2 && pHead1 != pHead2) {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};