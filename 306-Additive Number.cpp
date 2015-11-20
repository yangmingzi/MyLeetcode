/*
Additive number is a positive integer whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string represents an integer, write a function to determine if it's an additive number.
*/
class Solution {
public:
  bool isAdditiveNumber(string num) {
        //return isAdditiveHelper(num,10,1,2147483647,0);
        if(num.length()<3)
            return false;
        int step=0;
        //防止越界
        long front=0,second=0;
        for(int i=0;i<num.length()-1;){
            front=front*10+num[i]-'0';
            int j=i+1;
            second=0;
            for(;j<num.length();){
                if(j==i+1&&num[j]=='0'){
                    second=0;
                    if(isAdditiveHelper(num,j,front,second,0))
                        return true;
                    else
                        break;
                }else{
                    second=second*10+num[j]-'0';
                    if(isAdditiveHelper(num,j,front,second,0))
                        return true;
                    ++j;
                }
            }
            ++i;
        }
        return false;
    }

    bool isAdditiveHelper(string num,int step,long front,long second,int depth){
        if(depth==0&&step==num.length()-1)
            return false;
        else if(depth>0&&step==num.length()-1){
            return true;
        }
        string temp=num.substr(step+1,num.length()-step-1);
        long result_should=front+second;
        long res_get=0;
        int i=0;
        for(;i<temp.length();){
            if(i==0&&temp[i]=='0'){
                return false;
            }
            res_get=res_get*10+temp[i]-'0';
            if(res_get>result_should)
                return false;
            else if(res_get==result_should){
                return isAdditiveHelper(num,i+step+1,second,result_should,depth+1);
            }
            ++i;
        }
        return false;
    }
};