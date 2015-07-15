/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
class Solution {
public:
    int reverse(int x) {
         // Write your code here
        int rst = 0;
        
        while(x != 0){
            int next_rst = rst * 10 + x % 10;
            x = x / 10;
            if(next_rst/10 != rst) {
                rst  = 0;
                break;
            }
            rst = next_rst;
        }
        return rst;
    }
};

/*
下面的代码不行，会溢出，为什么？
class Solution {
public:
    int reverse(int x) {
        bool isPositive = true;
        if(x < 0){isPositive = false; x *= -1;}
        long long res = 0;//为了防止溢出，用long long
        while(x)
        {
            res = res*10 + x%10;
            x /= 10;
        }
        if(res > INT_MAX)return isPositive ? INT_MAX : INT_MIN;
        if(!isPositive)return res*-1;
        else return res;
    }
};
*/