class Solution:
    def StrToInt(self , s):
        if not s:
            return 0
        neg = False
        if s[0] == '-':
            neg = True
        if s[0] in '+-':
            s = s[1:]
        current = 0
        for ch in s:
            if ch not in '0123456789':
                return 0
            current *= 10
            current += int(ch)
        if neg:
            current *= (-1)
        return current