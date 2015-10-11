# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        if not array:
            return 0
        maxone = array[0]
        prevmax = array[0]
        for i in array[1:]:
            if prevmax < 0:
                prevmax = i
            else:
                prevmax = i + prevmax
            maxone = max(prevmax, maxone)
        return maxone