//将10进制数转化为26进制数
class Solution {
public:
    string convertToTitle(int n) {
        if(n<1){return "";}
        else{
            string result="";
            while(n){
                n--;//这一步很重要，实现了1->A，此后可以递加
                char c=n%26+'A';
                result+=c;
                n/=26;
            }
        reverse(result.begin(),result.end());//很重要，之前的排序是左低位右高位
        return result;
        }
    }
};