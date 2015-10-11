class Solution:
    def confirm(self, numbers, thatnumber):
        counter = 0
        for num in numbers:
            if num == thatnumber:
                counter += 1
        return counter > len(numbers) / 2
 
    def QuickFind(self, numbers, head, rear, k):
        if head >= rear:
            return 0
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
            return numbers[headsp]
        elif k - 1 > headsp:
            return self.QuickFind(numbers, headsp + 1, rear, k)
        else:
            return self.QuickFind(numbers, head, headsp, k)
 
    def MoreThanHalfNum_Solution(self, numbers):
        size = len(numbers)
        if not size:
            return 0
        if size == 1:
            return numbers[0]
        thatnumber = self.QuickFind(numbers, 0, size, size / 2)
        if self.confirm(numbers, thatnumber):
            return thatnumber
        else:
            return 0