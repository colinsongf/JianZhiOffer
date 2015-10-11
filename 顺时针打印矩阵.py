class Solution:
    def printMatrix(self, matrix):
        printresult = []
        row = len(matrix)
        if not row:
            return printresult
        col = len(matrix[0])
        start = (0, 0)
        while row > 0 and col > 0:
            sublist = self.printCircle(start, row, col, matrix)
            row -= 2
            col -= 2
            start = start[0] + 1, start[1] + 1
            printresult.extend(sublist)
        return printresult
    def printCircle(self, start, row, col, matrix):
        printresult = []
        i, j = start
        if row == 1 or col == 1:
            if row == col:
                printresult.append(matrix[i][j])
            elif row == 1:
                while j < start[1] + col:
                    printresult.append(matrix[i][j])
                    j += 1
            else:
                while i < start[0] + row:
                    printresult.append(matrix[i][j])
                    i += 1
            return printresult
        while j < start[1] + col:
            printresult.append(matrix[i][j])
            j += 1
        j -= 1
        printresult.pop()
        while i < start[0] + row:
            printresult.append(matrix[i][j])
            i += 1
        printresult.pop()
        i -= 1
        while j >= start[1]:
            printresult.append(matrix[i][j])
            j -= 1
        j += 1
        printresult.pop()
        while i >= start[0]:
            printresult.append(matrix[i][j])
            i -= 1
        printresult.pop()
        return printresult