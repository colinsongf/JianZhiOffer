class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        int i = 0, j = 0;
        while (j < size && ((array[j] & 0x1) == 1))
            ++j;
        while (i < size && j < size) {
            while (i < size && ((array[i] & 0x1) == 0))
                ++i;
            if (i == size)
                break;
            if (i < j) {
                ++i;
            } else {
                int pivot = array[i], p;
                for (p = i - 1;p >= j; --p) {
                    array[p + 1] = array[p];
                }  
                array[p + 1] = pivot;
                ++j;
            }  
        }  
    }
};