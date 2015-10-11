class Solution {
public:
    void InsertSort(vector<int>& numbers) {
        int i, j, pivot;
        for (i = 1;i < numbers.size(); ++i) {
            pivot = numbers[i];
            for (j = i - 1;j >=0 && numbers[j] > pivot;--j)
                numbers[j + 1] = numbers[j];
            numbers[j + 1] = pivot;
        }
    }
    bool IsContinuous(vector<int> numbers ) {
        if (numbers.size() == 0)
            return false;
        InsertSort(numbers);
        int diff = 0, size = numbers.size(), i, ksum;
        for (i = 0;i < size && numbers[i] == 0; ++i);
        ksum = i;
        for (i = i + 1;i < size; ++i) {
            if (numbers[i] == numbers[i - 1])
                return false;
            diff += numbers[i] - numbers[i - 1] - 1;
        }
        std::cout << diff << " " << ksum << std::endl;
        return diff <= ksum;
    }
};