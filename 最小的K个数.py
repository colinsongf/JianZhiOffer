class Solution:
    def QuickFind(self, numbers, head, rear, k):
        if head >= rear:
            return
        pivot = numbers[rear - 1]
        headsp, rearsp = head, rear - 2
        while headsp <= rearsp:
            while headsp < rear and numbers[headsp] < pivot:
                headsp += 1
            while rearsp >= head and numbers[rearsp] >= pivot:
                rearsp -= 1
            if headsp < rearsp:
                numbers[headsp], numbers[rearsp] = numbers[rearsp], numbers[headsp]
        numbers[headsp], numbers[rear - 1] = numbers[rear - 1], numbers[headsp]
        if k - 1 == headsp:
            return
        elif k - 1 > headsp:
            self.QuickFind(numbers, headsp + 1, rear, k)
        else:
            self.QuickFind(numbers, head, headsp, k)
 
    def GetLeastNumbers_Solution(self, numbers, k):
        size = len(numbers)
        if size < k:
            return []
        self.QuickFind(numbers, 0, size, k)
        return sorted(numbers[:k])