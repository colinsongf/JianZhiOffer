class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 1)
            return n;
        int prevprev = 0, prev = 1, t;
        int current = 1;
        while (current++ < n) {
            t = prev;
            prev = prev + prevprev;
            prevprev = t;
        }
        return prev;
    }
};