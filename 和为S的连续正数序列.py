class Solution:
    def subsum(self, a, b):
        return (a + b) * (b - a + 1) / 2
    def FindContinuousSequence(self, tsum):
        array = [x for x in range(1, tsum)]
        i, j = 0, 0
        answer=[]
        while i < tsum - 1 and j < tsum - 1:
            subSum = self.subsum(array[i], array[j])
            if subSum == tsum:
                subans = [x for x in range(array[i], array[j] + 1)]
                answer.append(subans)
                i += 1
                j += 1
            elif subSum > tsum:
                i += 1
            else:
                j += 1
        return answer