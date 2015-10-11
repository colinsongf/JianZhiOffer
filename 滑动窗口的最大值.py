class Stack:
    def __init__(self):
        self.stack = []
        self.maxstack = []
    def push(self, x):
        self.stack.append(x)
        if not self.maxstack or self.maxstack[-1] <= x:
            self.maxstack.append(x)
    def pop(self):
        topone = self.stack.pop()
        if topone == self.maxstack[-1]:
            self.maxstack.pop()
    def empty(self):
        return not self.stack
    def top(self):
        return self.stack[-1]
    def max(self):
        return self.maxstack[-1]
 
class Queue:
    def __init__(self):
        self.stack1 = Stack()
        self.stack2 = Stack()
    def enqueue(self, x):
        self.stack1.push(x)
    def dequeue(self):
        if self.stack2.empty():
            while not self.stack1.empty():
                one = self.stack1.top()
                self.stack1.pop()
                self.stack2.push(one)
        #ret = self.stack2.top()
        self.stack2.pop()
    def getmax(self):
        tmax = 0
        if not self.stack1.empty():
            tmax = self.stack1.max()
        if not self.stack2.empty():
            tmax = max(self.stack2.max(), tmax)
        return tmax
 
class Solution:
    def maxInWindows(self, num, size):
        queue = Queue()
        maxlist = []
        if len(num) < size or size == 0:
            return maxlist
        for i in range(size):
            queue.enqueue(num[i])
        maxlist.append(queue.getmax())
        for i in range(size, len(num)):
            queue.dequeue()
            queue.enqueue(num[i])
            maxlist.append(queue.getmax())
        return maxlist