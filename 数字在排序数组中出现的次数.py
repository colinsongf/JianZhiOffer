class Solution:
    def BinarySearchFirst(self, data, k):
        i, j = 0, len(data)
        firstplace = -1
        while i < j:
            mid = (i + j) >> 1
            if data[mid] == k:
                firstplace = mid
                j = mid
            elif data[mid] > k:
                j = mid
            else:
                i = mid + 1
        return firstplace
 
    def BinarySearchLast(self, data, k):
        i, j = 0, len(data)
        lastplace = -1
        while i < j:
            mid = (i + j) >> 1
            if data[mid] == k:
                lastplace = mid
                i = mid + 1
            elif data[mid] > k:
                j = mid
            else:
                i = mid + 1
        return lastplace
 
    def GetNumberOfK(self, data, k):
        i = self.BinarySearchFirst(data, k)
        j = self.BinarySearchLast(data, k)
        if i == -1:
            return 0
        return j - i + 1