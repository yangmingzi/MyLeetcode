// 两个指针首尾判断即可，跳过非字母数字字符，注意大小写
//while循环的写法很重要，i和j每次变化都要重新进入下一次循环，不能再一次循环内部一直检测
/*
不能写成这样
while(isAlphNum(s[x])==false) x++;
while(isAlphNum(s[y])==false) y--;
if(isSame(s[x],s[y])) {x++;y--;}
else return false;
否则如果输入是"!!!"，就会产生错误
*/
class Solution {
public:
    bool isPalindrome(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.length();
        if(len <= 1)return true;
        int i = 0, j = len - 1;
        while(i <= j)
        {
            if(isAlphanumeric(s[i]) == false)
                i++;
            else if(isAlphanumeric(s[j]) == false)
                j--;
            else 
            {
                if(isSame(s[i], s[j]) == true)
                    {i++; j--;}
                else return false;
            }
        }
        return true;
    }
    bool isAlphanumeric(char c)
    {
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9'))
            return true;
        else return false;
    }
    bool isSame(char a, char b)
    {
        if(a >= 'A' && a <= 'Z')
            a += 32;
        if(b >= 'A' && b <= 'Z')
            b += 32;
        return a == b;
    }
};
//二刷，速度相同但感觉逻辑更清晰
class Solution {
public:
    bool isLegal(char c){
        if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'))
            return true;
        else return false;
    }
    char upToLow(char c){
        return c+'a'-'A';
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        bool flag = true;
        while(i<j){
            if(!isLegal(s[i])){
                i++;
                continue;
            }
            if(!isLegal(s[j])){
                j--;
                continue;
            }
            if(s[i]>='A'&&s[i]<='Z'){
                s[i] = upToLow(s[i]);
            }
             if(s[j]>='A'&&s[j]<='Z'){
                s[j] = upToLow(s[j]);
            }
            if(s[i]!=s[j]){
                flag = false;
                break;
            }else{
                i++;
                j--;
            }
        }
        return flag;
    }
};