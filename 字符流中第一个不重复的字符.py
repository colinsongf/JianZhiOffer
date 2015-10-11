# -*- coding:utf-8 -*-
class Solution:
    # 返回对应char
    def __init__(self):
        self.counter = 0
        self.hash = {}
    def FirstAppearingOnce(self):
        # write code here
        answer = '#'
        minpos = 2**31 - 1
        for key in self.hash:
            value = self.hash[key]
            if value != -1 and value < minpos:
                minpos = value
                answer = key
        return answer
    def Insert(self, char):
        # write code here
        if char not in self.hash:
            self.hash[char] = self.counter
        else:
            self.hash[char] = -1
        self.counter += 1