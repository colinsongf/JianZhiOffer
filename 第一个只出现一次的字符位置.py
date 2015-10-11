# -*- coding:utf-8 -*-
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        counter = {}
        for ch in s:
            counter[ch] = counter.get(ch, 0) + 1
        for i, ch in enumerate(s):
            if counter[ch] == 1:
                return i
        return -1