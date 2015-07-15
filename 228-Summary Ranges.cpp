/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
/*
这道题题意是，将相邻的一组数据用区间表示。
虽然mark为easy，但是麻雀虽小，却五脏俱全，有很多陷阱的问题。

1、最开始想的是如下代码。但有几个问题需要注意一下。
一个就是可能溢出问题，这体现在两个方面，一个是自行编写的数字转字符串的代码中，另一个是在判断两个数是否相邻。
因为对c++不够了解，因此竟然不知道如何将数字转化成字符串，于是动手写了一个。
囧。这个版本的代码就像懒婆娘的裹脚布一样。
2、其实c++中可以直接将数字转化成字符串的。
在<string>头文件中，有这么一个方法to_string。
另外，判断是否相邻应该用不等号。
因此，精简后的代码如下。以上两个版本都是先在后面添加一个哨兵数据。
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> result;
        if(len == 0){
            return result;
        }
        int left = nums[0];
        nums.push_back(nums[len-1]);
        len++;
        for(int i=1; i<len; i++){
            if(nums[i] == nums[i-1] || nums[i] - nums[i-1] != 1){
                if(left == nums[i-1]){
                    result.push_back(to_string(left));
                }else{
                    result.push_back(to_string(left) + "->" + to_string(nums[i-1]));
                }
                left = nums[i];
            }
        }
        return result;
    }
};
3、在网上找到另外一种解决方案，非常优雅，其答题思路就是找到每个区间的左右两个端点，且无需哨兵。
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        int i=0;
        vector<string> result;
        while(i<len){
            int j=1;
            while(i+j<len && nums[i+j] - nums[i] == j) j++;
            result.push_back(j==1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return result;
    }
};