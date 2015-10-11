class Solution {
public:
    int Add(int num1, int num2) {
        int adder = 0;
        while (num2) {
            adder = num1 ^ num2;
            num2 = (num1 & num2) << 1;
            num1 = adder;
        }  
        return num1;
    }  
};