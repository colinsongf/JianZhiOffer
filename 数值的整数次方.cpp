class Solution {
public:
    bool similar(double number , int i) {
        return (number - i  < 0.00001 && -0.00001 < number - i);
    }
    double rPower(double base, unsigned int exp) {
        if (!exp)
            return 1;
        double subanswer = rPower(base, exp >> 1);
        subanswer *= subanswer;
        if (exp & 0x1)
            subanswer *= base;
        return subanswer;
    }
    double Power(double base, int exponent) {
        if (!exponent)
            return 1;
        if (similar(base, 0))
            return 0;
        if (similar(base ,1))
            return 1;
        bool neg = false;
        unsigned int exp;
        if (exponent < 0) {
            neg = true;
            exp = ~exponent + 1;
        } else {
            exp = exponent;
        }
        double answer = rPower(base, exp );
        return neg ? 1 / answer  : answer;
    }
};