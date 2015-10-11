class Solution {
public:
    int normalFindInRotateArray(vector<int> rotateArray, int head, int rear) {
        int min = rotateArray[head];
        for (int i = head + 1;i <= rear; ++i) {
            if (rotateArray[i] < min) {
                min = rotateArray[i];
            }
        }
        return min;
    }
 
    int minNumberInRotateArray(vector<int> rotateArray) {
        int rear = rotateArray.size() - 1;
        if (!rear)
            return rotateArray[0];
        int head = 0, mid;
        while (head <= rear) {
            if (head == rear || rotateArray[head] < rotateArray[rear]) {
                return rotateArray[head];
            }
            if (rotateArray[head] == rotateArray[rear]) {
                return normalFindInRotateArray(rotateArray, head, rear);
            }
            mid = (head + rear) >> 1;
            if (rotateArray[mid] >= rotateArray[head]) {
                head = mid + 1;
            } else {
                rear = mid;
            }
        }
        return 0;  
    }
};