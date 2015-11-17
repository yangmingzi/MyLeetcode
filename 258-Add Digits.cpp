/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/
//自己做，速度前列，8ms,35.62%
class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(true){
            while(num){
                sum +=(num%10);
                num/=10;
            }
            if(sum<10) break;
            num = sum;
            sum=0;
        }
        return sum;
    }
};