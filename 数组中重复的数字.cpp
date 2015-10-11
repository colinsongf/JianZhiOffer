class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    void swap(int data[], int p1, int p2) {
        int t = data[p1];
        data[p1] = data[p2];
        data[p2] = t;
    }
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;
        if (length < 2)
            return false;
        int i;
        for (i = 0;i < length; ++i) {
            if (numbers[i] == i)
                continue;
            while (numbers[i] != i) {
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers, i ,numbers[i]);
            }
        }
        return false;
    }
};