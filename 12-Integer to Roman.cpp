/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
/*
我们注意到罗马数字的字母是有规律的，
可以分成几组，I(1), V(5) 是一组， X(10), L(50)是一组，
C(100), D(500)是一组， M(1000), d(应该是D加一个上划线，表示5000) 是一组 ……。
后一组的两个数是前一组的10倍。
对于大于10的整数，我们把该整数逐位表示成罗马数字。 
个位上的数字1~9的分别为: I II III IV V VI VII VIII IX
十位上的数字1~9，只要把原来个位上的I 替换成 X， V 替换成L，X替换成C，即十位上的1~9表示的是10~90.
百位、千位以此类推。。。。。。
*/
class Solution {
public:
    string intToRoman(int num) {
        char romanChar[] = {'I','V','X','L','C','D','M'};
        string res;
        int i = 6, factor = 1000;
        while(num != 0)
        {
            helper(num / factor, &romanChar[i], res);
            i -= 2;
            num %= factor;
            factor /= 10;
        }
        return res;
    }
     
    void helper(int k, char romanChar[], string &res)
    {// 0 <= k <= 9
        if(k <= 0);
        else if(k <= 3)
            res.append(k, romanChar[0]);
        else if(k == 4)
        {
            res.push_back(romanChar[0]);
            res.push_back(romanChar[1]);
        }
        else if(k <= 8)
        {
            res.push_back(romanChar[1]);
            res.append(k-5, romanChar[0]);
        }
        else if(k == 9)
        {
            res.push_back(romanChar[0]);
            res.push_back(romanChar[2]);
        }
    }
};