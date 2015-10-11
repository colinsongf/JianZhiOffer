class Solution {
public:
     int NumberOf1(int n) {
         int counter = 0;
         while (n) {
             n &= (n - 1);
             ++counter;
         }
         return counter;
     }
};