/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/
//26进制转化成十进制
class Solution {
public:
    int titleToNumber(string s) {
       int res=0;
       for(int i=0;i<s.length();i++){
           res*=26;
           res+=(s[i]-'A'+1);
       }
       return res;
    }
};
//
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n){
            res = (char)((n-1)%26+'A')+res;
            n = (n-1)/26;
        }
        return res;
    }
};
//二刷，自己做
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        int cnt = 0;
        for(int i=s.size()-1;i>=0;i--){
            int tmp = s[i]-'A' + 1;
            sum  = sum + pow(26,cnt)*tmp;
            cnt++;
        }
        return sum;
    }
};