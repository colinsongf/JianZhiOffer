class Solution {
public:
    void ReverseString(string& str, int i, int j) {
        --j;
        while (i < j) {
            char t = str[i];
            str[i] = str[j];
            str[j] = t;
            ++i,--j;
        }
    }
 
    string LeftRotateString(string str, int n) {
        if (str.length() < 2)
            return str;
        n %= str.length();
        ReverseString(str, 0, n);
        ReverseString(str, n, str.length());
        ReverseString(str, 0, str.length());
        return str;
    }
};