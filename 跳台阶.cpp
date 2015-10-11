class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 2)
            return number;
        int prevprev = 1, prev = 2, t;
        int current = 2;
        while (current++ < number) {
            t = prev;
            prev = prev + prevprev;
            prevprev = t;
        }
        return prev;
    }
};