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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* head,*rear;
        head = rear = pListHead;
        unsigned int i = 0;
        while (i++ < k) {
            if (!rear)
                return NULL;
            rear = rear->next;
        }
        while (rear) {
            rear = rear->next;
            head = head->next;
        }
        return head;
    }
};