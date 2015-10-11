# -*- coding:utf-8 -*-
class Solution:
    def NextPermutation(self,sourceStr):
        size = len(sourceStr)
        i, j = size - 2, size - 1
        if size == 1:
            return None
        while i >= 0 and sourceStr[i] >= sourceStr[i + 1]:
            i -= 1
        if i == -1:
            return None
        while sourceStr[j] <= sourceStr[i]:
            j -= 1
        sourceStr[i], sourceStr[j] = sourceStr[j], sourceStr[i]
        sourceStr[i + 1:size] = sourceStr[i + 1:size][::-1]
        return sourceStr
 
    def Permutation(self, ss):
        answer = []
        if not ss:
            return answer
        sourceStr = sorted(ss)
        answer.append(''.join(sourceStr))
        nextStr = self.NextPermutation(sourceStr)
        while nextStr:
            answer.append(''.join(nextStr))
            nextStr = self.NextPermutation(nextStr)
        return answer