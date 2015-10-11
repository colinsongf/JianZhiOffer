class Solution {
public:
    int rectCover(int number) {
        if (number <= 1)
            return 1;
        int prevp = 1, prev = 1, t;
        int cur = 1;
        while (cur++ < number) {
            t = prev;
            prev += prevp;
            prevp = t;
        }
        return prev;
    }
};