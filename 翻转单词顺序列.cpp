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
    string ReverseSentence(string str) {
        int i, start, end;
        for (i = 0;i < str.length() && str[i] == ' ';++i);
        if (i == str.length())
            return str;
        start = i;
        for (end = start + 1;end < str.length(); ++end) {
            if (str[end] == ' ') {
                ReverseString(str, start, end);
                start = end + 1;
            }
        }
        ReverseString(str, start, str.length());
        ReverseString(str, 0, str.length());
        return str;
    }
};