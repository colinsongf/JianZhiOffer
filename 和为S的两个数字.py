class Solution:
    def FindNumbersWithSum(self, array, tsum):
        if not array or len(array) == 1:
            return []
        i, j = 0, len(array) - 1
        selecti,selectj = -1, -1
        minMutil = 2 ** 31
        while i < j:
            if array[i] + array[j] == tsum and minMutil > array[i] * array[j]:
                minMutil = array[i] * array[j]
                selecti, selectj = i, j
                i += 1
                j -= 1
            elif array[i] + array[j] > tsum:
                j -= 1
            else:
                i += 1
        return [array[selecti], array[selectj]] if selecti != -1 else []