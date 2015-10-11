/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead)
        return pHead;
        //step1:A-A'-B-B'
        RandomListNode* current = pHead, *nextone, *neibor, *newpHead;
        while (current) {
            nextone = current->next;
            current->next = new RandomListNode(current->label);
            current->next->next = nextone;
            current = nextone;
        }  
        //step2:copy rand
        current = pHead;
        while (current) {
            neibor = current->next;//must not NULL
            neibor->random = current->random ? current->random->next : NULL;
            current = neibor->next;
        }  
        //split
        current = pHead;
        newpHead = pHead->next;
        while (current) {
            neibor = current->next;
            nextone = neibor->next;
            current->next = nextone;
            neibor->next = nextone ? nextone->next : NULL;
            current = current->next;
        }  
        return newpHead;
    }  
};