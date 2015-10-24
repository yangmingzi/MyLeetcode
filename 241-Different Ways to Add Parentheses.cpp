/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int i;
        int val=0;
        for(i=0;i<input.size();i++){
            if(isdigit(input[i])){
                val*=10;
                val+=(input[i]-'0');
            }else{
                break;
            }
        }
        if(i==input.size()){return {val};}
        vector<int> res;
        int tmp;
        int n = input.size();
        int low = 0;
        int high = n-1;
        for(int i=0;i<n;i++){
            vector<int> left;
            vector<int> right;
            if(!isdigit(input[i])){
                left  = diffWaysToCompute(input.substr(0,i));
                right = diffWaysToCompute(input.substr(i+1,high-i));
                for(int p=0;p<left.size();p++){
                    for(int k=0;k<right.size();k++){
                        int tmp;
                        if(input[i] == '+'){
                            tmp = left[p]+right[k];
                        } else if(input[i] == '-'){
                            tmp = left[p] -right[k];
                        }else if(input[i] == '*'){
                            tmp = left[p] * right[k];
                        }
                        res.push_back(tmp);
                    }
                }
            }   
       
        }
        return res;
    }
};