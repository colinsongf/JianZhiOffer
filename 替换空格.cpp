class Solution {
public:
    void replaceSpace(char *str,int length) {
        int spaceSum = 0;
        for (int i = 0;i < length; ++i)
            if (*(str + i) == ' ')
                ++spaceSum;
        int sp = length + 2 * spaceSum;
        for (int i = length - 1;i >= 0; --i)
            if (*(str + i) == ' ') {
                str[--sp] = '0';
                str[--sp] = '2';
                str[--sp] = '%';
            } else {
                str[--sp] = str[i];
            }
    }
};