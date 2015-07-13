/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int res=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){//遇到空格，记录当前计数器的值，然后清零计数器
                if(cnt!=0){
                    res=cnt;
                    cnt=0;
                }
            }else cnt++;
        }
        return cnt==0?res:cnt;//防止以空格结尾的情况
    }
};