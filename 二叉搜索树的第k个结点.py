# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回对应节点TreeNode
    def KthNode(self, pRoot, k):
        # write code here
        if not pRoot:
            return None
        stack = []
        current = pRoot
        counter = 0
        while current or stack:
            while current:
                stack.append(current)
                current = current.left
            current = stack.pop()
            print current.val,
            counter += 1
            if k == counter:
                return current
            current = current.right
        return None