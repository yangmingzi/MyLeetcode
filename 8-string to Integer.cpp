/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/
//12ms,9.11%
class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        int sign = 1;
        const int len  = str.size();
        int i=0;
        while(str[i] == ' ' && i<len) i++;
        if(str[i] == '+') i++;
        else if(str[i]=='-') {sign=-1;i++;}//"+-2时应输出0"
        for(;i<len;i++){
            if(str[i]<'0' || str[i]>'9') break;
            if(num>INT_MAX/10 || (num==INT_MAX/10 &&(str[i]-'0')>INT_MAX%10)){
                return sign == -1?INT_MIN:INT_MAX;
            }
            num = num*10+(str[i]-'0');
        }
        return num*sign;
    }
};