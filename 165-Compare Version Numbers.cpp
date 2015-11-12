/*
ompare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
//比较版本号
//先比较.前面的值，如果相等，比较.后面的值
//注意理解两个while循环以及idx和val变量定义的位置
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int idx1=0,idx2=0;
        while(idx1<version1.length() || idx2<version2.length()){
            int val1=0;
            int val2=0;
            while(idx1<version1.length()){
                if(version1[idx1]=='.'){
                    idx1++;
                    break;
                }
                int a=version1[idx1]-'0';
                val1=val1*10+a;
                idx1++;
            }
            while(idx2<version2.length()){
                if(version2[idx2]=='.'){
                    idx2++;
                    break;
                }
                int a=version2[idx2]-'0';
                val2=val2*10+a;
                idx2++;
            }
            
            if(val1>val2) return 1;
            if(val1<val2) return -1;
            
        }
       return 0; 
        
    }
};
