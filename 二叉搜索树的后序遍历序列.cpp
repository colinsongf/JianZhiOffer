class Solution {
public:
    bool VerifySquenceOfBSTr(vector<int> sequence, int head, int rear) {
        if (head >= rear)
            return true;
        int root = sequence[rear - 1];
        int split, i;
        for (split = head;split < rear && sequence[split] < root; ++split);
        for (i = split;i < rear; ++i)
            if (sequence[i] < root)
                return false;
        return VerifySquenceOfBSTr(sequence, head, split) && VerifySquenceOfBSTr(sequence, split, rear - 1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if (!size)
            return false;
        return VerifySquenceOfBSTr(sequence, 0, size);
    }
};