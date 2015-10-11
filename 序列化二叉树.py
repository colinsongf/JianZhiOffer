# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def __init__(self):
        self.s = ''
    def Serialize(self, root):
        self.Serializer(root)
        return self.s.strip()
    def Serializer(self, root):
        if not root:
            self.s += ' #'
            return
        self.s += ' ' + str(root.val)
        self.Serializer(root.left)
        self.Serializer(root.right)
    def deserialize(self, s, sp):
        if sp >= len(s) or s[sp] == '#':
            return None, sp + 1
        root = TreeNode(int(s[sp]))
        sp += 1
        root.left , sp = self.deserialize(s, sp)
        root.right , sp = self.deserialize(s, sp)
        return root, sp
    def Deserialize(self, s):
        serialize = s.split(' ')
        tree, sp = self.deserialize(serialize, 0)
        return tree