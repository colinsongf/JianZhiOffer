class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int rowSize = array.size();
        if (rowSize == 0)
            return false;
        int colSize = array[0].size();
        if (colSize == 0)
            return false;
        int currentRowIndex = 0,currentColIndex = colSize - 1;
        while (currentRowIndex < rowSize && currentColIndex >= 0)
            if (array[currentRowIndex][currentColIndex] == target)
                return true;
            else if (array[currentRowIndex][currentColIndex] > target)
                --currentColIndex;
            else
                ++currentRowIndex;
         
        return false;
    }
};