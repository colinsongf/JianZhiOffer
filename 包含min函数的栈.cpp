class Solution {
public:
    void push(int value) {
        normalStack.push(value);
        if (minStack.empty() || minStack.top() >= value)
            minStack.push(value);
    }
    void pop() {
        int top = normalStack.top();
        normalStack.pop();
        if (minStack.top() == top)
            minStack.pop();
    }
    int top() {
        return normalStack.top();
    }
    int min() {
        return minStack.top();
    }
private:
    stack<int> normalStack;
    stack<int> minStack;
};