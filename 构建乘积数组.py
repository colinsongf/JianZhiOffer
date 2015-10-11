class Solution:
    def multiply(self, A):
        if len(A) < 2:
            return A[:]
        headA = [0 for i in A]
        rearA = [0 for i in A]
        headA[0] = A[0]
        for i in range(1, len(A)):
            headA[i] = headA[i - 1] * A[i]
        rearA[-1] = A[-1]
        for i in range(len(A) - 2, -1, -1):
            rearA[i] = rearA[i + 1] * A[i]
        B = [0 for i in A]
        for i in range(len(A)):
            if i == 0:
                B[0] = rearA[1]
            elif i == len(A) - 1:
                B[len(A) - 1] = headA[len(A) - 2]
            else:
                B[i] = headA[i - 1] * rearA[i + 1]
        return B