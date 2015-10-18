/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
//博客：http://www.cnblogs.com/felixfang/p/4064374.html
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

//算是自己写的吧。。。
class Solution {
public:
    int findMin(vector<int> &nums,int st,int co){
        int tmp = INT_MAX;
        int res = INT_MAX;
        for(int i = st;i<nums.size();i++){
            if(nums[i]>co && nums[i]<=tmp){
                tmp = nums[i];
                res = i;
            }
        }
        return res;
    }
    void swap(vector<int> &num, int left, int right){
        int temp = num[left];
        num[left] = num[right];
        num[right] = temp;
    }
    
    void rev(vector<int> &num, int start, int end){
        while(start < end){
            swap(num, start++, end--);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        int tmp;
        bool b = false;
        while(i>=0){
            if(nums[i]>=nums[i+1]){i--;}
            else{
                b = true;
                int k = findMin(nums,i+1,nums[i]);
                swap(nums,i,k);
                rev(nums,i+1,n-1);
            }
            if(b == true){break;}
        }
        if(b == false){
            reverse(nums.begin(),nums.end());
            return;
        }else{return;}
    }
};
//12ms.时间没变。但用stl简化了一下
class Solution {
public:
    int findMin(vector<int> &nums,int st,int co){
        int tmp = INT_MAX;
        int res = INT_MAX;
        for(int i = st;i<nums.size();i++){
            if(nums[i]>co && nums[i]<=tmp){
                tmp = nums[i];
                res = i;
            }
        }
        return res;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        int tmp;
        bool b = false;
        while(i>=0){
            if(nums[i]>=nums[i+1]){i--;}
            else{
                b = true;
                int k = findMin(nums,i+1,nums[i]);
                swap(nums[i],nums[k]);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
        }
        if(b == false){
            reverse(nums.begin(),nums.end());
            return;
        }
    }
};