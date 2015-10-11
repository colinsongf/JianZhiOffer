class Solution {
public:
    int FindNumAppearOnce(vector<int> data) {
        int flag = 0;
        vector<int>::iterator it;
        for (it = data.begin();it != data.end(); ++it) {
            flag ^= *it;
        }
        return flag;
    }
    void swap(int *p1, int *p2) {
        if (*p1 > *p2) {
            int t = *p1;
            *p1 =  *p2;
            *p2 = t;
        }
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int flag = 0;
        *num1 = *num2 = 0;
        if (data.size() < 2)
            return;
        vector<int>::iterator it;
        for (it = data.begin();it != data.end(); ++it) {
            flag ^= *it;
        }
        int split = 1;
        while ((split & flag) == 0) {
            split <<= 1;
        }
        vector<int> data1, data2;
        for (it = data.begin();it != data.end(); ++it) {
            if ((*it) & split)
                data1.push_back(*it);
            else
                data2.push_back(*it);
        }
        *num1 = FindNumAppearOnce(data1);
        *num2 = FindNumAppearOnce(data2);
        swap(num1,num2);
    }
};