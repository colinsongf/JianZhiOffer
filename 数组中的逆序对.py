class Solution:
    def mergeSort(self, data, head, rear):
        if head >= rear - 1:
            return 0
        mid = (head + rear) >> 1
        left = self.mergeSort(data, head, mid)
        right = self.mergeSort(data, mid, rear)
        current = 0
        i, j = head, mid
        tempdata = []
        while i < mid and j < rear:
            if data[i] <= data[j]:
                tempdata.append(data[i])
                i += 1
            else:
                tempdata.append(data[j])
                j += 1
                current += mid - i
        while i < mid:
            tempdata.append(data[i])
            i += 1
        while j < rear:
            tempdata.append(data[j])
            j += 1
        j = 0
        for i in range(head, rear):
            data[i] = tempdata[j]
            j += 1
        return current + left + right
 
    def InversePairs(self, data):
        size = len(data)
        if size < 2:
            return 0
        return self.mergeSort(data, 0, size)