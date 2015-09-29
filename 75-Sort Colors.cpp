/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/
//四种解法：http://www.cnblogs.com/ganganloveu/p/3703746.html
class Solution {
public:
    void sortColors(int A[], int n) {
        int num1=0,num2=0,num3=0;
        for(int i=0;i<n;++i)
        {
            if (A[i]==0) num1++;
            if (A[i]==1) num2++;
            if (A[i]==2) num3++;
        }
      //需要注意此处的逻辑
      int k=0;
      while(num1--) A[k++]=0;
      while(num2--) A[k++]=1;
      while(num3--) A[k++]=2;
    }
};
//计数排序,扫两遍
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int k = 0;
        for(int p=0;p<n;p++){
            if(nums[p] == 0){i++;}
            else if(nums[p]==1){j++;}
            else{k++;}
        }
        for(int p=0;p<n;p++){
            if(p<i){nums[p]=0;}
            else if(p>=i && p<i+j){nums[p]=1;}
            else{nums[p]=2;}
        }
    }
};
//扫一遍
/*
如果只能扫一遍，很容易想到的就是左边存放0和1，右边存放2.两边往中间靠。

设置两个index，left记录第一个1的位置，left左边为0，right记录第一个非2的位置，right右边为2.

然后使用i从头到尾扫一遍，直到与right相遇。

i遇到0就换到左边去，遇到2就换到右边去，遇到1就跳过。

需要注意的是：由于left记录第一个1的位置，因此A[left]与A[i]交换后，A[left]为0,A[i]为1，因此i++；

而right记录第一个非2的位置，可能为0或1，因此A[right]与A[i]交换后，A[right]为2,A[i]为0或1，i不能前进，要后续判断。

由此该数组分为4段：[0,left)-->0; [left,i)-->1; [i,right]-->乱序; (right,n-1]-->2

0  0  0  1  1  1  2  1  0  2  1  2  2  2

           ^         ^             ^

          left         i            right
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left = 0;
        int right = n-1;
        int i = 0;
        while(i <= right)
        {
            if(nums[i] == 0)
            {
                swap(nums[left], nums[i]);
                left ++;
                i ++;
            }
            else if(nums[i] == 1)
            {
                i ++;
            }    
            else
            {
                swap(nums[i], nums[right]);
                right --;
            }
        }
    }
};
//巧妙做法,平移插入
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=-1;
        int j=-1;
        int k=-1;
        int n=nums.size();
        for(int p=0;p<n;p++){
            if(nums[p]==0){
                nums[++k]=2;
                nums[++j]=1;
                nums[++i]=0;
            }
            else if(nums[p]==1){
                nums[++k]=2;
                nums[++j]=1;
            }
            else{
                nums[++k]=2;
            }
        }
    }
};

