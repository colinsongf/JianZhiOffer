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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* nextone, *prev = NULL;
        while (pHead) {
            nextone = pHead->next;
            pHead->next = prev;
            prev= pHead;
            pHead = nextone;
        }
        return prev;
    }
};