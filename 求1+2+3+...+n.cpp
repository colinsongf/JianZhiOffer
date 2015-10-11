class Base {
public:
    Base() {
        ++counter;
        sum += counter;
    }
    static int Result() {
        return sum;
    }
    static void Clear() {
        counter = 0;
        sum = 0;
    }
private:
    static int counter ;
    static int sum;
};
 
int Base::counter = 0;
int Base::sum = 0;
 
class Solution {
public:
    int Sum_Solution(int n) {
        Base::Clear();
        Base* p = new Base[n];
        delete[] p;
        return Base::Result();
    }
};