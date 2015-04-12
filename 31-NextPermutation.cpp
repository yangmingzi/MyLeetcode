//词典顺序：后缀递增，内部递减

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int end = num.size() - 1;
        int povit = end;
		//找到第一个破坏词典顺序的位置
        while(povit > 0){
            if(num[povit] > num[povit - 1]) break;
            povit --;
        }
		//仅对破坏顺序的部分进行 处理
		//在逆序单位之后的部分是符合字典顺序的
		//因其后缀是按递减顺序排列的，所以逆序单位是要被替换的
		//找到第一个逆序单位大的数字，交换
		//对逆序单位后面的数字进行递减排序
        if(povit > 0){
            povit --; 
            int large = end;
            while(num[large] <= num[povit]) large --;
            swap(num[large] , num[povit]);
            reverse(num.begin() + povit + 1 , num.end());
        }else{
            reverse(num.begin() , num.end());
        }
    }
};